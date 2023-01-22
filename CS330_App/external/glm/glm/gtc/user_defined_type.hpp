#pragma once

// Dependencies
#include "../detail/setup.hpp"
//#include "../detail/precision.hpp"
#include "../detail/type_vec1.hpp"
#include "../detail/type_vec2.hpp"
#include "../detail/type_vec3.hpp"
#include "../detail/type_vec4.hpp"

#if(defined(GLM_MESSAGES) && !defined(GLM_EXT_INCLUDED))
#	pragma message("GLM: GLM_GTC_std_type extension included")
#endif

namespace glm
{
    namespace type
    {
        void func(){}
    }

    using namespace type;

    /// @addtogroup gtc_std
    /// @{



    /// @}
}//namespace glm