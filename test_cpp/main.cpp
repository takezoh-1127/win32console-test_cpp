#include <Windows.h>
#include <stdio.h>
#include <iostream>



#ifndef PI
	#define PI	(3.14f)
#endif


#undef PI

//namespace Math
//{

const float PI = 3.14f;



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
		//printf("### PI:[%f]\n", Math::PI);
		printf("### PI:[%f]\n", PI);
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

	return 0;
}
