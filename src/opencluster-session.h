//-----------------------------------------------------------------------------
//   libopencluster-session
//   -------
//   library to enable an authenticated and encrypted session with an opencluster service.
//
//   Copyright (C) 2017  Clinton Webb

/*
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser Public License for more details.

    You should have received a copy of the GNU Lesser Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
//-----------------------------------------------------------------------------

#ifndef __LIBOPENCLUSTER_SESSION_H
#define __LIBOPENCLUSTER_SESSION_H

/*
 * Version 0.10
*/

#include <stdint.h>


#define OC_SESSION_VERSION 0x00001000
#define OC_SESSION_VERSION_NAME "v0.10.00"



///////////////////////////////////////////
// instance handle.   
typedef void * OCSESSION;



///////////////////////////////////////////
// declare the public functions.

// init and shutdown.
OCSESSION ocsession_init(void);
void ocsession_shutdown(OCSESSION instance);



#endif
