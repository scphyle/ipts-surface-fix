#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x0feb1e94, "usleep_range_state" },
	{ 0xc281f1fb, "prepare_to_wait_event" },
	{ 0x68a1b6c6, "__wake_up" },
	{ 0x9e3808e7, "hid_allocate_device" },
	{ 0x31b85143, "__dynamic_dev_dbg" },
	{ 0x5b0c0638, "hid_destroy_device" },
	{ 0xd272d446, "__fentry__" },
	{ 0x4f51989c, "wake_up_process" },
	{ 0x5a844b26, "__x86_indirect_thunk_rax" },
	{ 0xd272d446, "dump_stack" },
	{ 0xe8213e80, "_printk" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0x6ac784f4, "schedule_timeout" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0x11e98b2f, "_dev_info" },
	{ 0x90a48d82, "__ubsan_handle_out_of_bounds" },
	{ 0x7a5ffe84, "init_wait_entry" },
	{ 0x8efcc8cd, "down_write" },
	{ 0x0d67fa3a, "devm_kfree" },
	{ 0x11e98b2f, "_dev_err" },
	{ 0x8efcc8cd, "up_write" },
	{ 0xbd03ed67, "random_kmalloc_seed" },
	{ 0x9aa6980d, "mutex_lock" },
	{ 0xf7050fde, "dma_alloc_attrs" },
	{ 0x26c6bd5e, "mei_cldev_recv" },
	{ 0x4f1e5fd0, "__list_del_entry_valid_or_report" },
	{ 0x5a9688dc, "mei_cldev_driver_unregister" },
	{ 0x0b12d1b3, "kthread_stop" },
	{ 0x8637e971, "__mei_cldev_driver_register" },
	{ 0xe54e0a6b, "__fortify_panic" },
	{ 0x0e9cab28, "memset" },
	{ 0x11e98b2f, "_dev_warn" },
	{ 0x62cbec20, "wait_for_completion" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xe804603d, "__init_waitqueue_head" },
	{ 0x62cbec20, "complete_all" },
	{ 0x8efcc8cd, "down_read" },
	{ 0x13e01a9a, "hid_input_report" },
	{ 0xb8d8e3ca, "kthread_create_on_node" },
	{ 0xf413a875, "dma_set_coherent_mask" },
	{ 0x76140b5a, "mei_cldev_send" },
	{ 0x87a53462, "dma_free_attrs" },
	{ 0x9aa6980d, "mutex_unlock" },
	{ 0xd76f9d10, "mei_cldev_enable" },
	{ 0x2f9595d1, "__kmalloc_cache_noprof" },
	{ 0xcfdc0e1b, "mei_cldev_get_drvdata" },
	{ 0xf413a875, "dma_set_mask" },
	{ 0x58247aa0, "hid_parse_report" },
	{ 0x7a6661ca, "ktime_get_seconds" },
	{ 0x9921a8e4, "mei_cldev_register_rx_cb" },
	{ 0x80f39fc5, "mei_cldev_set_drvdata" },
	{ 0xe4de56b4, "__ubsan_handle_load_invalid_value" },
	{ 0x8efcc8cd, "up_read" },
	{ 0x67628f51, "msleep" },
	{ 0x7851be11, "__SCT__might_resched" },
	{ 0x4944b104, "kmalloc_caches" },
	{ 0xf7b54576, "hid_add_device" },
	{ 0x9aa6980d, "mutex_init_generic" },
	{ 0xd76f9d10, "mei_cldev_disable" },
	{ 0x4198ed14, "__init_rwsem" },
	{ 0xdc352a3b, "__list_add_valid_or_report" },
	{ 0xe1b0a92a, "wait_for_completion_timeout" },
	{ 0xdc0e35f8, "devm_kmalloc" },
	{ 0x534ed5f3, "__msecs_to_jiffies" },
	{ 0xd710adbf, "__kmalloc_noprof" },
	{ 0x40a621c5, "snprintf" },
	{ 0xc2ccdd1e, "__init_swait_queue_head" },
	{ 0xb730487b, "finish_wait" },
	{ 0xfbe7861b, "memcpy" },
	{ 0xcb8b6ec6, "kfree" },
	{ 0xe63769e7, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x0feb1e94,
	0xc281f1fb,
	0x68a1b6c6,
	0x9e3808e7,
	0x31b85143,
	0x5b0c0638,
	0xd272d446,
	0x4f51989c,
	0x5a844b26,
	0xd272d446,
	0xe8213e80,
	0xbd03ed67,
	0x6ac784f4,
	0xd272d446,
	0x11e98b2f,
	0x90a48d82,
	0x7a5ffe84,
	0x8efcc8cd,
	0x0d67fa3a,
	0x11e98b2f,
	0x8efcc8cd,
	0xbd03ed67,
	0x9aa6980d,
	0xf7050fde,
	0x26c6bd5e,
	0x4f1e5fd0,
	0x5a9688dc,
	0x0b12d1b3,
	0x8637e971,
	0xe54e0a6b,
	0x0e9cab28,
	0x11e98b2f,
	0x62cbec20,
	0xd272d446,
	0xe804603d,
	0x62cbec20,
	0x8efcc8cd,
	0x13e01a9a,
	0xb8d8e3ca,
	0xf413a875,
	0x76140b5a,
	0x87a53462,
	0x9aa6980d,
	0xd76f9d10,
	0x2f9595d1,
	0xcfdc0e1b,
	0xf413a875,
	0x58247aa0,
	0x7a6661ca,
	0x9921a8e4,
	0x80f39fc5,
	0xe4de56b4,
	0x8efcc8cd,
	0x67628f51,
	0x7851be11,
	0x4944b104,
	0xf7b54576,
	0x9aa6980d,
	0xd76f9d10,
	0x4198ed14,
	0xdc352a3b,
	0xe1b0a92a,
	0xdc0e35f8,
	0x534ed5f3,
	0xd710adbf,
	0x40a621c5,
	0xc2ccdd1e,
	0xb730487b,
	0xfbe7861b,
	0xcb8b6ec6,
	0xe63769e7,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"usleep_range_state\0"
	"prepare_to_wait_event\0"
	"__wake_up\0"
	"hid_allocate_device\0"
	"__dynamic_dev_dbg\0"
	"hid_destroy_device\0"
	"__fentry__\0"
	"wake_up_process\0"
	"__x86_indirect_thunk_rax\0"
	"dump_stack\0"
	"_printk\0"
	"__ref_stack_chk_guard\0"
	"schedule_timeout\0"
	"__stack_chk_fail\0"
	"_dev_info\0"
	"__ubsan_handle_out_of_bounds\0"
	"init_wait_entry\0"
	"down_write\0"
	"devm_kfree\0"
	"_dev_err\0"
	"up_write\0"
	"random_kmalloc_seed\0"
	"mutex_lock\0"
	"dma_alloc_attrs\0"
	"mei_cldev_recv\0"
	"__list_del_entry_valid_or_report\0"
	"mei_cldev_driver_unregister\0"
	"kthread_stop\0"
	"__mei_cldev_driver_register\0"
	"__fortify_panic\0"
	"memset\0"
	"_dev_warn\0"
	"wait_for_completion\0"
	"__x86_return_thunk\0"
	"__init_waitqueue_head\0"
	"complete_all\0"
	"down_read\0"
	"hid_input_report\0"
	"kthread_create_on_node\0"
	"dma_set_coherent_mask\0"
	"mei_cldev_send\0"
	"dma_free_attrs\0"
	"mutex_unlock\0"
	"mei_cldev_enable\0"
	"__kmalloc_cache_noprof\0"
	"mei_cldev_get_drvdata\0"
	"dma_set_mask\0"
	"hid_parse_report\0"
	"ktime_get_seconds\0"
	"mei_cldev_register_rx_cb\0"
	"mei_cldev_set_drvdata\0"
	"__ubsan_handle_load_invalid_value\0"
	"up_read\0"
	"msleep\0"
	"__SCT__might_resched\0"
	"kmalloc_caches\0"
	"hid_add_device\0"
	"mutex_init_generic\0"
	"mei_cldev_disable\0"
	"__init_rwsem\0"
	"__list_add_valid_or_report\0"
	"wait_for_completion_timeout\0"
	"devm_kmalloc\0"
	"__msecs_to_jiffies\0"
	"__kmalloc_noprof\0"
	"snprintf\0"
	"__init_swait_queue_head\0"
	"finish_wait\0"
	"memcpy\0"
	"kfree\0"
	"module_layout\0"
;

MODULE_INFO(depends, "hid,mei");

MODULE_ALIAS("mei:*:3e8d0870-271a-4208-8eb5-9acb9402ae04:*:*");

MODULE_INFO(srcversion, "C1EEFCDDD400905AABAFAAF");
