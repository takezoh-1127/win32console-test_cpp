#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <random>
#include <array>
#include <vector>

// C++11
using int32 = int;

// C++98
//typedef int int32

// C++11
using func = void(*)(int);

// C++98
//typedef void(*func)(int)

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

	return 0;
}
