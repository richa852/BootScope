#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "bootscope"

static ssize_t bootscope_read(struct file *file,
                              char __user *buffer,
                              size_t length,
                              loff_t *offset)
{
    const char message[] = "BootScope Linux Driver is active.\n";
    size_t message_len = sizeof(message) - 1;

    if (*offset >= message_len)
        return 0;

    if (length > message_len - *offset)
        length = message_len - *offset;

    if (copy_to_user(buffer, message + *offset, length))
        return -EFAULT;

    *offset += length;

    return length;
}

static const struct file_operations bootscope_fops = {
    .owner = THIS_MODULE,
    .read = bootscope_read,
};

static struct miscdevice bootscope_device = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = DEVICE_NAME,
    .fops = &bootscope_fops,
    .mode = 0444,
};

static int __init bootscope_init(void)
{
    int result;

    result = misc_register(&bootscope_device);

    if (result != 0) {
        pr_err("BootScope: device registration failed\n");
        return result;
    }

    pr_info("BootScope: driver loaded successfully\n");

    return 0;
}

static void __exit bootscope_exit(void)
{
    misc_deregister(&bootscope_device);

    pr_info("BootScope: driver unloaded\n");
}

module_init(bootscope_init);
module_exit(bootscope_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BootScope");
MODULE_DESCRIPTION("Simple Linux device driver for BootScope");
MODULE_VERSION("1.0");
