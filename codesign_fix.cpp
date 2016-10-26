#include "substrate.h"

typedef int32_t CSSM_RETURN;
enum {
    CSSM_OK = 0
};

struct TPCertGroup;

static CSSM_RETURN fake_check(TPCertGroup &certGroup) {
	return CSSM_OK;
}

__attribute__((constructor))
static void fix_all_the_things() {
	MSImageRef image = MSGetImageByName("/System/Library/Frameworks/Security.framework/Security");
	CSSM_RETURN (*tpCheckCertificateAllowList)(TPCertGroup &) = (CSSM_RETURN (*)(TPCertGroup &))MSFindSymbol(image, "_tpCheckCertificateAllowList");
    MSHookFunction(tpCheckCertificateAllowList, &fake_check);
}
