#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"
static void gci_register_hooks(apr_pool_t *p);
static int gci_handler(request_rec *req);

static int gci_handler(request_rec *req) {

    if(!req->handler || strcmp(req->handler, "gci_handler")) return (DECLINED);
    ap_rputs("GCI 2019", req);
    return OK;

}

static void gci_register_hooks(apr_pool_t *p) {
    ap_hook_handler(gci_handler, NULL, NULL, APR_HOOK_LAST);
}

module AP_MODULE_DECLARE_DATA gci_module = {
    STANDARD20_MODULE_STUFF, 
    NULL, /* create per-dir    config structures */
    NULL, /* merge  per-dir    config structures */
    NULL, /* create per-server config structures */
    NULL, /* merge  per-server config structures */
    NULL, /* table of config file commands       */
    gci_register_hooks  /* register hooks */
};