/* vi:set ts=8 sts=8 sw=8:
 *
 * Practical Music Search
 * Copyright (c) 2006-2011  Kim Tore Jensen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _PMS_SONGLIST_H_
#define _PMS_SONGLIST_H_

#include "song.h"
#include "search.h"
#include <string>
#include <vector>

using namespace std;

class Songlist
{
	public:
		Songlist();
		~Songlist();

		Song *			at(unsigned int spos);
		Song *			operator[] (unsigned int spos) { return at(spos); };

		vector<Song *>		songs;
		string			title;
		Searchresultset	*	searchresult;
		search_mode_t		searchmode;

		/* Can we make local modifications? */
		bool			readonly;

		/* Is this the main playlist? */
		bool			playlist;

		/* Playlist version at MPD side */
		long long		version;

		/* Add or replace a song */
		void			add(Song * song);

		/* Remove all songs from the list */
		void			clear();

		/* Get a random song position within boundaries */
		size_t			randpos();

		/* Truncate the list and resize the vector */
		void			truncate(unsigned long length);

		/* Size */
		size_t			size();

		/*
		 * Search functions
		 */
		
		/* Find by hash value */
		size_t			find(long hash, size_t pos = 0);

		/* Same as find(), but looks only through search results */
		size_t			sfind(long hash, size_t pos = 0);

		/* Search for songs using song fields. */
		Song *			search(search_mode_t mode);
		Song *			search(search_mode_t mode, long mask, string terms);

};

#endif /* _PMS_SONGLIST_H_ */
