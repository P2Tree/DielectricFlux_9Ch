/**
 *
 * Copyright (C) 2016 Yang Liuming <dicksonliuming@gmail.com>
 *
 * This file is part of DielectricFlux
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GUN General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * alonfg with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *************************************************************/

/**
 *
 * \file    main.cpp
 * \brief   Enter of DielectricFlux Project
 * \author  Yang Liuming <dicksonliuming@gmail.com>
 * \version V1.0
 * \date    2016.5
 *
 * ***********************************************************/

#include "System_main.h"
#include "buttomwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    System_main();      // only for windows initialization & event initialization

    return a.exec();
}
