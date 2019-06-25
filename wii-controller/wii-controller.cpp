/*
 * This file is part of Wii-Scale
 * Copyright © 2015 Andreas Älveborn
 * Copyright © 2016-2017 Matt Robinson
 *
 * This has been modified to enable the Wii Balance Board to be used
 * as a controller for Bumper Car Sumo senior project 
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

#include <iostream>
#include <string>
#include <chrono>
#include <deque>
#include <numeric>

#include <xwiimote.h>

#include "XWiiMonitor.h"

using namespace std;

std::unique_ptr<XWiiIface> board;

std::unique_ptr<XWiiIface> connect()
{
    XWiiMonitor monitor;
    std::unique_ptr<XWiiIface> device;

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
    printf("Wii-Scale started\n");

    board = connect();
    if(board == nullptr)
    {
        return 0;
    }
    
    // Controller
    while(1)
    {
        struct xwii_event event;
        board->Dispatch(XWII_EVENT_WATCH | XWII_EVENT_BALANCE_BOARD, &event);

        if(event.type == XWII_EVENT_WATCH)
        {
            // Board has disconnected
            printf("DISCONNECTED\n");
            board = nullptr;
			return 0;
        }

        for(int i = 0; i < 4; i++)
        {
            printf("%d\n",event.v.abs[i].x);
        }
    }
}
