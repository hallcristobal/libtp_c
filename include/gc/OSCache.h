// Taken from https://github.com/zsrtp/GC-Randomizer/blob/stable/include/gc/OSCache.h
#pragma once

#include <stdint.h>

namespace gc::os_cache
{
	extern "C"
	{
		// DCEnable
		// DCInvalidateRange
		void DCFlushRange(void* startAddr, uint32_t nBytes);
		// DCStoreRange
		// DCFlushRangeNoSync
		// DCStoreRangeNoSync
		// DCZeroRange
		void ICInvalidateRange(void* startAddr, uint32_t nBytes);
		// ICFlashInvalidate
		// ICEnable
		// __LCEnable
		// LCEnable
		// LCDisable
		// LCStoreBlocks
		// LCStoreData
		// LCQueueWait
		// L2GlobalInvalidate
		// DMAErrorHandler
		// __OSCacheInit
	}
}