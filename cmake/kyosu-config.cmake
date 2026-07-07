##======================================================================================================================
##  POLYFLOAT - Extended precision floating points
##  Copyright : Polyfloat Contributors & Maintainers
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================

##======================================================================================================================
## Reuse install.cmake to preapre package properly
##======================================================================================================================
include("${CMAKE_CURRENT_LIST_DIR}/polyfloat-targets.cmake")
set(POLYFLOAT_LIBRARIES polyfloat::polyfloat)
