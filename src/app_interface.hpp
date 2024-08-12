#ifndef _APP_INTERFACE_
#define _APP_INTERFACE_

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

#include "app_util.hpp"

#include "smakes/construct_risc_v.hpp"
#include "smakes/construct_state.hpp"
#include "smakes/generate_code.hpp"
#include "smakes/generate_state.hpp"

#include "sdatas/memory_cell.hpp"
#include "sdatas/memory.hpp"
#include "sdatas/port.hpp"
#include "sdatas/reg.hpp"
#include "sdatas/state.hpp"
#include "sdatas/word.hpp"

#include "sutils/color.hpp"
#include "sutils/error_output.hpp"
#include "sutils/slog.hpp"
#include "sutils/utility.hpp"

#endif
