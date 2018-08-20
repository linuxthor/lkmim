# lkmim
Load kernel module in memory. 

Quick demo of loading an LKM from a buffer in memory. Two methods are shown: 

1) Directly loading an LKM from a buffer in memory with the init_module() syscall. 
2) Loading an LKM from a memfd_create() created file with finit_module() (via a symlink as it wouldn't seem to work directly(??))

The second method is a lot more convoluted and is provided here as a PoC. The normal way of doing this is shown in the first one!
