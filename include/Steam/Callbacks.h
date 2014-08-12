#ifndef __CALLBACKS_H__
#define __CALLBACKS_H__
//#include <file>
using namespace System;
using namespace System::Collections::Generic;

void DoCheckCheat();

public ref class CallbackBase
{
public:
	CCallbackBase* _callback;
	int _callType;
};

public ref class ResultBase
{
public:
	void* _res;
	int _callType;
	SteamAPICall_t _callID;
	int _size;
};

public ref class Callbacks
{
public:
	static List<CallbackBase^>^ _callbacks;
	static List<ResultBase^>^ _results;
	static Dictionary<SteamAPICall_t, bool>^ _calls;
	static Dictionary<SteamAPICall_t, CallbackBase^>^ _callResults;
	static SteamAPICall_t _lastRegisteredCall;

	static Callbacks()
	{
		_callbacks = gcnew List<CallbackBase^>();
		_results = gcnew List<ResultBase^>();
		_calls = gcnew Dictionary<SteamAPICall_t, bool>();
		_callResults = gcnew Dictionary<SteamAPICall_t, CallbackBase^>();
		_lastRegisteredCall = 0;
	}

	static SteamAPICall_t RegisterCall()
	{		
		_lastRegisteredCall ++;
		_calls->Add( _lastRegisteredCall, false );

		return _lastRegisteredCall;
	}

	static void Register( CCallbackBase* call, int type )
	{		
		CallbackBase^ callback = gcnew CallbackBase();
		callback->_callback = call;
		callback->_callType = type;		
		_callbacks->Add( callback );
	}
	
	static void RegisterCallResult( CCallbackBase* call, SteamAPICall_t callID )
	{		
		CallbackBase^ callback = gcnew CallbackBase();
		callback->_callback = call;		
		_callResults->Add( callID, callback );
	}

	static void UnregisterCall( CCallbackBase* call )
	{
		for each( CallbackBase^ callback in _callbacks )
		{
			if( callback->_callback == call )
			{				
				_callbacks->Remove( callback );
			}
		}
	}

	static void Return( void* res, int type, SteamAPICall_t callID, int size )
	{		
		_calls[ callID ] = true;
		ResultBase^ callback = gcnew ResultBase();
		callback->_res = res;
		callback->_callType = type;
		callback->_callID = callID;
		callback->_size = size;		
		_results->Add( callback );
	}

	static void Run()
	{		
		List<ResultBase^>^ data = _results->GetRange( 0, _results->Count );

		for each( ResultBase^ result in data )
		{
			for each( KeyValuePair<SteamAPICall_t, CallbackBase^>^ current in _callResults )
			{
				if( result->_callID == current->Key )
				{
					current->Value->_callback->Run( result->_res, false, result->_callID );
				}
			}
		}

		_results->Clear();
	}
};

#endif /* __CALLBACKS_H__ */
