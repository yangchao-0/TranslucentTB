#pragma once
#define _X86_
#include <memory>
#include <ostream>
#include <string>
#include <tuple>
#include <windef.h>
#include <WinBase.h>

class Log {

private:
	static std::unique_ptr<std::wostream> m_LogStream;
	static std::tuple<HRESULT, std::wstring> InitStream();
	// The normal AutoLocalFree would call Error::Handle even tho we aren't done initializing the log stream
	struct LocalFreeUnsafeDeleter {

		inline void operator() (void *data)
		{
			LocalFree(data);
		}

	};

public:
	// If you set this outside of the class I'll burn you alive.
	static std::wstring File;
	static void OutputMessage(const std::wstring &message);
};