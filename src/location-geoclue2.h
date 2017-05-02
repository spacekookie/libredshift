/* location-geoclue2.h -- Geoclue2 location provider header
   This file is part of Redshift.

   Redshift is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Redshift is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Redshift.  If not, see <http://www.gnu.org/licenses/>.

   Copyright (c) 2014  Jon Lund Steffensen <jonlst@gmail.com>
*/

#ifndef REDSHIFT_LOCATION_GEOCLUE2_H
#define REDSHIFT_LOCATION_GEOCLUE2_H

#include <stdio.h>

#include <redshift.h>


int location_geoclue2_init(void *state);
int location_geoclue2_start(void *state);
void location_geoclue2_free(void *state);

void location_geoclue2_print_help(FILE *f);
int location_geoclue2_set_option(void *state,
				 const char *key, const char *value);

int location_geoclue2_get_location(void *state,
				   location_t *loc);


#endif /* ! REDSHIFT_LOCATION_GEOCLUE2_H */
