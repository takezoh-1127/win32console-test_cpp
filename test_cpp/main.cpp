#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <random>
#include <array>
#include <vector>
#include <memory>
#include <cassert>

// C++11
using int32 = int;
//using int32 = short;

// C++98
//typedef int int32

using uint8 = unsigned char;

// C++11
using func = void(*)(int);

// C++98
//typedef void(*func)(int)


static_assert(sizeof(uint8) == 1, "ERROR : uint8 size is not 1");
//static_assert(sizeof(int32) == 2,"");
static_assert(sizeof(int32) == 4, "ERROR : int32 size is not 4");

static_assert(std::is_pod<int32>::value, "ERROR : int32 is not POD");

namespace xe
{

	typedef unsigned int uint32;

	using uint16 = unsigned short;

	namespace math
	{
		float DegreeToRadian(float const& deg) { return 0.0f; }
	}

	namespace Math
	{
		float DegreeToRadian(float const& deg) { return 0.0f; }
	}
}

namespace Xe
{
	using uint16 = unsigned short;

	namespace Math
	{
		float DegreeToRadian(float const& deg) { return 0.0f; }
	}
}

namespace XE
{
	using uint16 = unsigned short;

	namespace Math
	{
		float DegreeToRadian(float const& deg) { return 0.0f; }
	}
}

#ifndef PI
	#define PI	(3.14f)
#endif


#undef PI

namespace Math
{

#define	HALF_PI	(3.14f * 0.5f)

const float PI = 3.14f;

}


constexpr float DegPerRad() { return (180.0f / 3.14f); }

//const float DegPerRad = (180.0f / 3.14f);

// 例えばRadianをDegreeに変換するtempleteを作成した場合、引数の型によって返却値の型も変わってしまうので正しい処理にならない.
// 引数でintが来るとfloatに変換されると言われてワーニングになる.
template<class T>
T RadToDeg(T const& rad)
{
	return rad * (180.0f / 3.14f);
}

// 返却値をfloatで固定するとdoubleの引数だとfloatに変換されるとワーニングになる.
template<class T>
float RadToDeg2(T const& rad)
{
	return rad * (180.0f / 3.14f);
	//return static_cast<float>(rad) * (180.0f / 3.14f);
}

// auto、decltypeを使えば引数の型は何が来てもdecltypeで決められた型（この場合はfloat）が返却値の型になる.
template<class T>
auto DRadToDeg(T const& rad) -> decltype(rad * (180.0f / 3.14f))
{
	return rad * (180.0f / 3.14f);
}

// floatで処理するならこれじゃダメ？.
float FRadToDeg(float const& rad)
{
	return rad * (180.0f / 3.14f);
}

//}


void actual_function(int arg)
{
	printf("### void actual_function(int arg) : [%d]\n", arg);
}


// C++98

// 定義が衝突する.
#if 0
enum Team
{
	Red,
	White,
};

enum Palette
{
	Red,
	Green,
	Blue,
};
#endif

#if 0
enum Team
{
	Red,
	White,
};

namespace color
{
	enum Palette
	{
		Red,
		Green,
		Blue,
	};
}
#endif

#if 0
// 名前の衝突を避けるためスコープを作る必要がある.
struct Team
{
//public:
	enum
	{
		Red,
		White,
	};
};

struct Palette
{
public:
	enum
	{
		Red,
		Green,
		Blue,
	};
};
#endif

enum class Team
{
	Red,
	White,
};

enum class Palette : uint8
{
	Red,
	Green,
	Blue,

	//Max = 0xffffffff,
};

enum class Attribute
{
	Fire,
	Water,
};

// C++98
//#define NULL	(0)

// C++11
// 組み込みでnullptrが用意されているのでこちらを使用する.


namespace
{
	// 奇数か？.
	bool is_odd(int i)
	{
		return ((i % 2) != 0);
	}
}


class Enemy
{
public:
	Enemy()
		: HP(100)
		, attackPower(10)
	{
		printf("### Enemy::Enemy()\n");
	}

	~Enemy()
	{
		printf("### Enemy::~Enemy()\n");
	}

	int GetHP() const { return HP; }

private:
	int HP;
	int attackPower;
};

struct HogeHoge
{
	int a;
};


class Hoge
{
	// コピーコンストラクタを無効.
	Hoge(const Hoge&) = delete;
	// 代入演算子を無効.
	Hoge operator=(Hoge&) = delete;
};

// C++98
// privateにして無効にしていた.
//class Hoge
//{
//private:
	// コピーコンストラクタを無効.
	//Hoge(const Hoge&) = delete;
//};


int main()
{
	printf("### hello world.\n");

	std::cout << "### hello world.(C++)" << std::endl;

	OutputDebugStringA("### trace test.\n");
	OutputDebugString(L"### trace test2.\n");

	//TRACE("### trace test3.\n");
	//ATLTRACE("### trace test4.\n");

	//_RPTN(_CRT_WARNING, "### trace test2.\n");

	{
		// typedefでもnamespaceで括られているときはxe::を付ける必要がある.
		//uint32 ui32 = 0;
		xe::uint32 ui32 = 0;

		//uint16 ui16 = 0;
		xe::uint16 ui16 = 0;

		{
			float rad = xe::math::DegreeToRadian(90.0f);
		}

		{
			float rad = xe::Math::DegreeToRadian(90.0f);
		}
	}

	{
		Xe::uint16 ui16 = 0;

		float rad = Xe::Math::DegreeToRadian(90.0f);
	}

	{
		XE::uint16 ui16 = 0;

		float rad = XE::Math::DegreeToRadian(90.0f);
	}

	{
		// defineはnamespaceは関係無い.
		printf("### PI:[%f] HALF_PI:[%f]\n", Math::PI, HALF_PI);
	}

	{
		auto f = RadToDeg(1.0f);
		auto d = RadToDeg(1.0);
		auto i = RadToDeg(1);

		//printf("### [%f][%f][%f].\n",f,d,i);
		printf("### [%f][%f][%d].\n", f, d, i);
	}

	{
		auto f = RadToDeg2(1.0f);
		auto d = RadToDeg2(1.0);
		auto i = RadToDeg2(1);

		//printf("### [%f][%f][%f].\n",f,d,i);
		printf("### [%f][%f][%f].\n", f, d, i);
	}

	{
		auto f = DRadToDeg(1.0f);
		auto d = DRadToDeg(1.0);
		auto i = DRadToDeg(1);

		//printf("### [%f][%f][%f].\n",f,d,i);
		printf("### [%f][%f][%f].\n", f, d, i);
	}

	{
		auto f = FRadToDeg(1.0f);
		auto d = FRadToDeg(1.0);
		auto i = FRadToDeg(1);

		//printf("### [%f][%f][%f].\n",f,d,i);
		printf("### [%f][%f][%f].\n", f, d, i);
	}

	{
		int32 i = 128;

		printf("### [%d]\n", i);
	}

	{
		// この場合はintになってしまう？.
		auto i = 128;
	}

	{
		func fp = &actual_function;

		fp(10);
	}

	{
		std::mt19937 rnd;

	}

	{
		Team team = Team::Red;

		Attribute attr = Attribute::Fire;

	}

	{
		std::array<int, 10> ar = { 0,10,20,30,40,50,60,70,80,90 };

//		ar.fill(10);

		printf("### array size:[%d]\n", ar.size());

		for (auto i : ar)
		{
			printf("   [%d]\n", i);
		}
		
		// 要素外にアクセスするとランタイムでエラーになる.
		// releaseビルドだとエラーにならない？.
		//ar[10] = 100;
	}

	{
		std::vector<int> v;

		v.push_back(10);

		v.emplace_back(20);

		for (auto i : v)
		{
			printf("   v:[%d]\n", i);
		}
	}

	{
		class Point2
		{
		public:
			Point2(int inX,int inY)
				: x(inX)
				, y(inY)
			{}

			int x;
			int y;
		};

		std::vector<Point2> v;

		// push_backだとPoint2のコピーが発生する.
		v.push_back(Point2(10, 20));

		// emplace_backだと直に書き込むため無駄なコピーが発生しない.
		v.emplace_back(100, 200);
		// これも書けるがこれだとやはり無駄なコピーが発生している？.
		v.emplace_back(Point2(1000, 2000));

		for (auto p : v)
		{
			printf("   v:[%d][%d]\n", p.x,p.y);
		}
	}

	// ラムダ式.

	// count_if
	// 第３引数で与えられる単項関数の条件を満たす要素が配列やコンテナにいくつ含まれているかを返すテンプレート関数.
	{
		std::vector<int> v = { 0,1,2,3,4,5,6,7,8,9,10 };

		printf("### count_if\n");

		printf("### size:[%d]\n", v.size());

		for (auto i : v)
		{
			printf("   [%d]\n", i);
		}

		// C++98
		{
			size_t count = std::count_if(v.begin(), v.end(), is_odd);

			printf("### count odd : [%d]\n", count);
		}

		// C++11
		{
			// ラムダ式で記述.
			size_t count = std::count_if(v.begin(), v.end(), 
											[](int i)->bool { return ((i % 2) != 0); }
										);

			printf("### count odd : [%d]\n", count);
		}
	}

	// shared_ptrのテスト.
	{
		std::shared_ptr<Enemy> pp;

		{
			printf("### new Enemy\n");

			// この書き方はダメ？.
			//std::shared_ptr<Enemy> p = new Enemy();

			// shared_ptrにセットする場合はコンストラクタで渡すようにする.
			//std::shared_ptr<Enemy> p(new Enemy());

			//
			std::shared_ptr<Enemy> p = std::shared_ptr<Enemy>(new Enemy());

			// newを直接書かない方法が推奨されている.
			//std::shared_ptr<Enemy> p = std::make_shared<Enemy>();

			pp = p;

			printf("### scope end\n");
		}

		printf("### scope end\n");
	}

	{
		std::weak_ptr<Enemy> wp;

		{
			// newしたshared_ptrは一つのみにする.
			// それ以外で参照、保持したい場合はweak_ptrを使う.
			std::shared_ptr<Enemy> sp(new Enemy);

			wp = sp;

			// wptrではアクセスできない.
			//auto hp = wp->GetHP();

			if (wp.expired())
			{
				// 期限切れ（つまりは無効なポインタ）.
				printf("### wp expired.\n");
			}
			else
			{
				// 期限切れではない（つまり有効なポインタ）.
				printf("### wp not expired.\n");

				auto p = wp.lock();

				if (p)
				{
					auto hp = p->GetHP();

					printf("### enemy hp : [%d]\n", hp);
				}
			}
		}
		
		if (wp.expired())
		{
			printf("### wp expired.\n");

			auto p = wp.lock();

			// shared_ptrを取得して無効な場合はnullptrになる.
			//assert(p);

			if (p)
			{
				printf("### wptr is not nullptr\n");
			}
			else
			{
				printf("### wptr is nullptr\n");
			}
		}
		else
		{
			printf("### wp not expired.\n");
		}
	}

	{
		std::array<int, 5> arr = { 5,3,6,8,2 };

		std::sort(arr.begin(), arr.end());

		for (auto i : arr)
		{
			printf("   i:[%d]\n", i);
		}
	}

#if 0
	{
		int* p = nullptr;

		// releaseビルドでは無効になる.
		assert(p);
	}
#endif

	// POD.
	{
#if 1
		if (std::is_pod<int32>::value)
		{
			printf("### int32 is POD.\n");
		}
		else
		{
			printf("### int32 is not POD.\n");
		}
#endif

		if (std::is_pod<HogeHoge>::value)
		{
			printf("### HogeHoge is POD.\n");
		}
		else
		{
			printf("### HogeHoge is not POD.\n");
		}

		if (std::is_pod<Enemy>::value)
		{
			printf("### Enemy is POD.\n");
		}
		else
		{
			printf("### Enemy is not POD.\n");
		}
	}
	return 0;
}
