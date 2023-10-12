#include "./zns.h"
#include <math.h>
#include <signal.h>
/*
    将请求分发到各个芯片中
*/    
typedef struct chip_transaction{
    int req;

}chip_transaction;

typedef struct ChipQueue{
    QTAILQ_HEAD(chip_list, chip_transaction) chip_list;
}ChipQueue;

static void advance_chip_queue_status(){
    ChipQueue* c;
    QTAILQ_INIT(c->chip_list);
    QTAILQ_INSERT_AFTER(&c->chip_list,);
}

// static void req_distribute(FemuCtrl *n, NvmeNamespace *ns, NvmeCmd *cmd, NvmeRequest *req){
    
// }
void req_distribute(NvmeRequest *req, ZNS *zns){
    NvmeRwCmd *rw = (NvmeRwCmd *)&req->cmd;
    struct NvmeNamespace *ns = req->ns;
    struct zns_ssdparams * spp = &zns->sp; 
    uint64_t slba = le64_to_cpu(rw->slba); // slba单位为512B
    //块数从0开始计数，这里+1是为了修正计数
    uint32_t nlb = (uint32_t)le16_to_cpu(rw->nlb) + 1; //块数从0开始计数，这里+1是为了修正计数
    uint64_t currlat = 0, maxlat = 0;

    
    uint64_t num_of_concurrent_zones;
    //
    if(req->cmd_opcode == NVME_CMD_WRITE){
        
    }else{

    }
}