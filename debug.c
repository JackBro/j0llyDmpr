/**
 *   j0llyDmpr
 *   Copyright (C) 2010 Souchet Axel <0vercl0k@tuxfamily.org>
 *
 *   This file is part of j0llyDmpr.
 *
 *   J0llyDmpr is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   J0llyDmpr is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with J0llyDmpr. If not, see <http://www.gnu.org/licenses/>.
**/
#include "debug.h"

#include <string.h>

FILE *fpDbgManager = NULL;

UCHAR initDbgManager()
{
	SIZE_T sizeStr = 0;
    DWORD status = 0, idLast = 0, i = 0;
    UCHAR path[MAX_PATH] = {0};
    BOOL ret = FALSE;

    status = GetModuleFileName(NULL,
        path,
        MAX_PATH
    );

    if(status == 0)
        return 0;

    sizeStr = strlen(path);
    for(; i < sizeStr; ++i)
        if(path[i] == '\\')
            idLast = i;

    memset(path+idLast+1, 0, sizeStr - (idLast + 1));
    ret = SetCurrentDirectory(path);
    if(ret == FALSE)
        return 0;

    fpDbgManager = fopen(FILE_LOG, "a");
    return (fpDbgManager == NULL) ? 0 : 1;
}
