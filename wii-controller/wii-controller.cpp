/*
 * This file is part of Wii-Scale
 * Copyright © 2015 Andreas Älveborn
 * Copyright © 2016-2017 Matt Robinson
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <bluetooth/bluetooth.h>

#include "xwiimote.h"
#include "XWiiMonitor.h"

using namespace std;

unique_ptr<XWiiIface> board;

std::unique_ptr<XWiiIface> connect()
{
    XWiiMonitor monitor;
    unique_ptr<XWiiIface> device;

    while(device = monitor.Poll())
    {
        if(!device->HasBalanceBoard())
        {
            // Not a balance board, try the next device
            continue;
        }

        device->EnableBalanceBoard();
        return device;
    }
    return nullptr;
}

int main(int argc, const char* argv[])
{
    
    printf("Wii Controller started\n");

    board = connect();

   
    if(board == nullptr)
    {
        printf("Board Not Connected\n");
        return 0;
    }
   
    while(1)
    {
        if(!board)
        {
            continue;
        }
        
        struct xwii_event event;
        board->Dispatch(XWII_EVENT_WATCH | XWII_EVENT_BALANCE_BOARD, &event);

        if(event.type == XWII_EVENT_WATCH)
        {
            board = nullptr;
            continue;
        }

        for(int i = 0; i < 4; i++)
        {
            printf("%d\t", event.v.abs[i].x);
        }

        printf("\n");
    }
    
    return 0;
}
