#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <string_view>
#include <thread>

//TODO: Add text sound

namespace util
{

	class delayed_stream
	{
	private:

		bool fast = false;
		bool running = true;
		std::thread t0;

		inline void delay(char c)
		{
			if (fast)
				return;
			switch (c)
			{
			case '.':
				Sleep(300);
				break;
			case ',':
				Sleep(100);
				break;
			case ':':
				Sleep(300);
				break;
			case ';':
				Sleep(300);
				break;
			case '!':
				Sleep(300);
				break;
			case '?':
				Sleep(300);
				break;
			default:
				Sleep(25);
			}
		}

	public:

		inline void startThread()
		{
			running = true;
			t0 = std::thread{ [this] {
			while (running)
			{
				if (GetKeyState(' ') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
					fast = true;
			}
			}
			};
		}

		inline void StopThread() {
			running = false;
			t0.join();
		}

		delayed_stream& operator<<(std::string input)
		{
			fast = false;
			for (char c : input)
			{
				std::cout << c;

				delay(c);
			}
			fast = false;
			Sleep(500);
			return *this;
		}

		delayed_stream& operator<<(int input)
		{
			fast = false;
			std::string stringInt = std::to_string(input);
			for (char c : stringInt)
			{
				std::cout << c;

				delay(c);
			}
			fast = false;
			Sleep(500);
			return *this;
		}

		delayed_stream& operator<<(double input)
		{
			fast = false;
			std::string stringDouble = std::to_string(input);
			stringDouble.erase(stringDouble.find_last_not_of('0') + 1, std::string::npos);
			for (char c : stringDouble)
			{
				std::cout << c;

				delay(c);
			}
			fast = false;
			Sleep(500);
			return *this;
		}
	};
	static delayed_stream slow{};

	class slow_stream
	{
	private:

		bool fast = false;
		bool running = true;
		std::thread t0;

		inline void delay(char c)
		{
			if (fast)
				return;
			switch (c)
			{
			case '.':
				Sleep(100);
				break;
			case ',':
				Sleep(35);
				break;
			case ':':
				Sleep(100);
				break;
			case ';':
				Sleep(100);
				break;
			case '!':
				Sleep(100);
				break;
			case '?':
				Sleep(100);
				break;
			default:
				Sleep(5);
			}
		}

	public:

		inline void startThread()
		{
			running = true;
			t0 = std::thread{ [this] {
			while (running)
			{
				if (GetKeyState(' ') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
					fast = true;
			}
			}
			};
		}

		inline void StopThread() {
			running = false;
			t0.join();
		}

		slow_stream& operator<<(std::string input)
		{
			fast = false;
			for (char c : input)
			{
				std::cout << c;

				delay(c);
			}
			fast = false;
			return *this;
		}

		slow_stream& operator<<(int input)
		{
			fast = false;
			std::string stringInt = std::to_string(input);
			for (char c : stringInt)
			{
				std::cout << c;

				delay(c);
			}
			fast = false;
			return *this;
		}

		slow_stream& operator<<(double input)
		{
			fast = false;
			std::string stringDouble = std::to_string(input);
			stringDouble.erase(stringDouble.find_last_not_of('0') + 1, std::string::npos);
			for (char c : stringDouble)
			{
				std::cout << c;

				delay(c);
			}
			fast = false;
			return *this;
		}
	};

	static slow_stream fast{};
}
