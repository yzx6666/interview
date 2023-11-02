#include <mutex>
#include <atomic>

// 饿汉模式，线程安全
#if 0
class Singleton
{
public:
	Singleton* getInstance()
	{
		return instance;
		atexit(Destructor)
	}
private:
	Singleton() = default;
	~Singleton() = default;
	Singleton(const Singleton&) = default;
	Singleton& operator =(const Singleton&) = default;

	static void Destructor()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}

	static Singleton* instance;
};

Singleton* Singleton::instance = new Singleton;
#endif

//-----------------------------------------------
// 懒汉模式 双重校验锁保证线程安全
#if 0
class Singleton
{
public:
	static Singleton* getInstance()
	{
		if (instance == nullptr)
		{
			std::lock_guard<std::mutex> lock(mtx);
			if (instance == nullptr)
			{
				instance = new Singleton;
				atexit(Destructor);
			}
		}
		return instance;
	}

private:
	Singleton() = default;
	~Singleton() = default;
	Singleton(const Singleton&) = default;
	Singleton& operator = (const Singleton&) = default;

	static Singleton* instance;
	static std::mutex mtx;
	static void Destructor()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;
#endif

//-----------------------------------------------
// 懒汉模式 原子操作保证线程安全
#if 1
class Singleton
{
public:
	static Singleton* getInstance()
	{
		Singleton* tmp = instance.load(std::memory_order_relaxed);
		atomic_thread_fence(std::memory_order_acquire); // 获取内存屏障
		if (tmp == nullptr) {
			std::lock_guard<std::mutex> lock(mtx);
			tmp = instance.load(std::memory_order_relaxed);
			if (tmp == nullptr) {
				tmp = new Singleton;
				atomic_thread_fence(std::memory_order_release); // 释放内存屏障
				instance.store(tmp, std::memory_order_relaxed);
				atexit(Destructor);
			}
		}
		return tmp;
	}

private:
	Singleton() = default;
	~Singleton() = default;
	Singleton(const Singleton&) = default;
	Singleton& operator = (const Singleton&) = default;

	static std::atomic<Singleton*> instance;
	static std::mutex mtx;
	static void Destructor()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}
};

std::atomic<Singleton*> Singleton::instance = nullptr;
#endif

//-------------------------------------------
//c++11 magic static 特性：如果当变量在初始化的时候，并发同时进⼊声明语句，并发线程将 会阻塞等待初始化结束
#if 0
class Singleton
{
public:
	static Singleton& GetInstance() {
		static Singleton instance;
		return instance;
	}
private:
	Singleton() = default;
	~Singleton() = default;
	Singleton(const Singleton&) = default;
	Singleton& operator=(const Singleton&) = default;
};
#endif // 0

