#ifndef LIB_TP_FLAG
#define LIB_TP_FLAG

#include <stdint.h>

class Flag {
private:
	uint32_t addr;
	uint8_t bit;

public:
	Flag(uint32_t addr, uint8_t bit) : addr(addr), bit(bit) {}
	void activate();
	void deactivate();
	bool is_active();
	void toggle();
};
namespace Flags {
	struct TempFlags {
		uint8_t flags[0x20];
	};  // struct TempFlags
	static_assert(sizeof(TempFlags) == 0x20);

	struct GlobalFlags {
		uint8_t flags[0x20];
	};
	static_assert(sizeof(GlobalFlags) == 0x20);

	struct EventFlags {
		uint8_t flags[0x168];
	}__attribute__((packed));
	static_assert(sizeof(EventFlags) == 0x168);
};      // namespace Flags
#endif  // LIB_TP_FLAG