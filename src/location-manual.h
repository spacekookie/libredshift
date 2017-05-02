/* location-manual.h -- Manual location provider header
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

   Copyright (c) 2010-2014  Jon Lund Steffensen <jonlst@gmail.com>
*/

#ifndef REDSHIFT_LOCATION_MANUAL_H
#define REDSHIFT_LOCATION_MANUAL_H

#include <stdio.h>

#include <redshift.h>


typedef struct {
	location_t loc;
} location_manual_state_t;


int location_manual_init(location_manual_state_t *state);
int location_manual_start(location_manual_state_t *state);
void location_manual_free(location_manual_state_t *state);

void location_manual_print_help(FILE *f);
int location_manual_set_option(location_manual_state_t *state,
			       const char *key, const char *value);

int location_manual_get_location(location_manual_state_t *state,
				 location_t *loc);


#endif /* ! REDSHIFT_LOCATION_MANUAL_H */
