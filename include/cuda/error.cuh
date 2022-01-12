#ifndef ERROR_CUH_
#define ERROR_CUH_

cudaError_t e;

// Error checking macro
#define cudaCheckError(addr)							\
	e = cudaGetLastError();							\
	if (e != cudaSuccess) {							\
		printf("Cuda failure %s:%d: '%s' (addr = %p)\n", __FILE__,	\
				__LINE__, cudaGetErrorString(e), addr);		\
		exit(-1);							\
	}

// Allocation
#define cuda_device_alloc(ptr, size)	\
	cudaMalloc(ptr, size);		\
	cudaCheckError(ptr);

// Copying
#define cuda_host_to_device_memcpy(dst, src, size)		\
	cudaMemcpy(dst, src, size, cudaMemcpyHostToDevice);	\
	cudaCheckError(dst);

#define cuda_device_to_host_memcpy(dst, src, size)		\
	cudaMemcpy(dst, src, size, cudaMemcpyDeviceToHost);	\
	cudaCheckError(dst);

// Deallocation
#define cuda_device_free(ptr) {		\
	cudaFree(ptr);			\
	cudaCheckError(ptr);		\
}

// Memory status
void cuda_check_memory_status(const char *file, size_t line)
{
	size_t free_mem;
	size_t total_mem;

	cudaMemGetInfo(&free_mem, &total_mem);

	printf("At [%s:%lu]: %lu bytes total, of which %lu bytes are free.\n",
			file, line, total_mem, free_mem);
}

#define cuda_show_mem()					\
	cuda_check_memory_status(__FILE__, __LINE__);

#endif
