#include <core/common_defines.h>
#include <lib/nfc/nfc.h>
#include "../js_modules.h"

static void js_test(struct mjs* mjs) {
    mjs_return(mjs, mjs_mk_string(mjs, "Hello from NFC", ~0, true));
}

static void* js_nfc_create(struct mjs* mjs, mjs_val_t* object) {
    mjs_val_t nfc_obj = mjs_mk_object(mjs);
    mjs_set(mjs, nfc_obj, "test", ~0, MJS_MK_FN(js_test));
    *object = nfc_obj;

    return (void*)1;
}
/*
static void js_nfc_destroy(void* inst) {

}*/

static const JsModuleDescriptor js_nfc_desc = {
    "nfc",
    js_nfc_create,
    NULL,
};
static const FlipperAppPluginDescriptor plugin_descriptor = {
    .appid = PLUGIN_APP_ID,
    .ep_api_version = PLUGIN_API_VERSION,
    .entry_point = &js_nfc_desc,
};
const FlipperAppPluginDescriptor* js_nfc_ep(void) {
    return &plugin_descriptor;
}