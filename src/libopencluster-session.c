//-----------------------------------------------------------------------------
/*
    libopencluster-session
    see opencluster-session.h for details.
    Copyright (C) 2017  Clinton Webb

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser Public License for more details.

    You should have received a copy of the GNU Lesser Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.


*/
//-----------------------------------------------------------------------------



#include "opencluster-session.h"

#include <assert.h>
#include <stdlib.h>

#if (OC_SESSION_VERSION != 0x00001000)
#error "Incorrect header version.  code and header versions must match."
#endif

// A Random number that is applied to every ocsession_t structure to verify that the pointer is actually pointing to an initiated object.
// NOTE: This identifier should change when functional changes are made to the structure.
#define OCSESSION_STRUCT_VERIFIER 84957858




typedef struct {
	long long verifier;
} ocsession_t;




//--------------------------------------------------------------------------------------------------
// Initialise everything we need to initialise.   This will return a pointer to a ocsession_t structure 
// that has been allocated and initialised.  
OCSESSION ocsession_init(void)
{
	ocsession_t *r;

	// Assume some sane type sizes.    
	assert(sizeof(short) == 2);
	assert(sizeof(int) == 4);
	// (long) by itself could be either 4 or 8, depending on if it is running on 32-bit or 64-bit system.
	assert(sizeof(long long) == 8);
	
	r = calloc(1, sizeof(ocsession_t));
	r->verifier = OCSESSION_STRUCT_VERIFIER;

	// ....
	
	assert(r->verifier == OCSESSION_STRUCT_VERIFIER);
	return(r);
}



//--------------------------------------------------------------------------------------------------
// Clean up the structure that were created by the library.  
void ocsession_shutdown(OCSESSION r)
{
	// if a NULL was passed in, then the developer has probably made a mistake.
	assert(r != NULL);
	if (r != NULL) {
		ocsession_t *session = (ocsession_t *) r;

		// Verify that the object referenced by the pointer appears to be a valid OCSESSION structure.
		assert(session->verifier == OCSESSION_STRUCT_VERIFIER);
		if (session->verifier != OCSESSION_STRUCT_VERIFIER) {
			return;
		}

		// ....
		
		// we allocated the space, so we need to free it.
		free(session);	session = NULL;
	}
}




