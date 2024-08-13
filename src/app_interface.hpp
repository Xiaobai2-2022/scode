#ifndef _APP_INTERFACE_
#define _APP_INTERFACE_

#include "senv/s_env_setting.hpp"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

#include "sdatas/memory_cell.hpp"
#include "sdatas/memory.hpp"
#include "sdatas/port.hpp"
#include "sdatas/reg.hpp"
#include "sdatas/state.hpp"
#include "sdatas/word.hpp"

#include "smakes/construct_risc_v.hpp"
#include "smakes/construct_state.hpp"
#include "smakes/generate_code.hpp"
#include "smakes/generate_state.hpp"

#include "sutils/error_output.hpp"
#include "sutils/slog.hpp"
#include "sutils/sstyle.hpp"
#include "sutils/sys_util.hpp"
#include "sutils/utility.hpp"

#include "svm/svm.hpp"

#endif
