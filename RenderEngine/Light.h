
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Nnanna Kama : Simple LIGHT STRUCT:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef KS_LIGHT_H
#define KS_LIGHT_H

#include <Maths\ks_Maths.h>

namespace ks {


	struct Light
	{
		vec3 position;
		vec3 color;

		static Light create(const vec3& pPos, const vec3& pCol);

		static const Light& getDefault();
	};
}

#endif