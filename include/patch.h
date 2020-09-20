// Taken from https://github.com/zsrtp/GC-Randomizer/blob/stable/include/patch.h
#pragma once

#include <stdint.h>
#include "gc/OSCache.h"
#include "system.h"

namespace mod::patch
{
	void writeBranch(void* ptr, void* destination);
	void writeBranchLR(void* ptr, void* destination);
	void writeBranchMain(void* ptr, void* destination, uint32_t branch);

	template<typename Func, typename Dest>
	Func hookFunction(Func function, Dest destination)
	{
		uint32_t* instructions = reinterpret_cast<uint32_t*>(function);

		uint32_t* trampoline = reinterpret_cast<uint32_t*>(malloc(2 * sizeof(uint32_t)));

		// Original instruction
		trampoline[0] = instructions[0];
		gc::os_cache::DCFlushRange(&trampoline[0], sizeof(uint32_t));
		gc::os_cache::ICInvalidateRange(&trampoline[0], sizeof(uint32_t));

		// Branch to original function past hook
		writeBranch(&trampoline[1], &instructions[1]);

		// Write actual hook
		writeBranch(&instructions[0], reinterpret_cast<void*>(static_cast<Func>(destination)));

		return reinterpret_cast<Func>(trampoline);
	}
}
