
#ifndef KS_DEFINES_H
#define KS_DEFINES_H

#define MAX_NAME		64

#define ks_max(a, b)	(a) > (b) ? (a) : (b)
#define ks_min(a, b)	(a) < (b) ? (a) : (b)

#ifndef NULL
#define NULL 0
#endif


#ifndef VOID_RETURN_IF_NULL
#define VOID_RETURN_IF_NULL(x)	{ if( (x)==0 ) return; }
#endif


#ifndef BOOL_RETURN_IF_NULL
#define BOOL_RETURN_IF_NULL(x)	{ if( (x)==0 ) return false; }
#endif


#ifndef SAFE_DELETE
#define SAFE_DELETE(x)	{ if( (x)!=0 ) {delete (x); (x)=0;} }
#endif


#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x) { if( (x)!=0 ) { delete [] (x); x=0; }	}
#endif


#if (defined _MSC_VER)
#define ks_thread_local		__declspec( thread )
#else
#define ks_thread_local		__thread
#endif // _MSC_VER


typedef unsigned int	ksU32;
typedef ksU32			ksType;
typedef ksU32			u32;
typedef int				ks32;
typedef float			f32;
typedef const f32		constf32;
typedef unsigned short	ksUShort;
typedef short			ksShort;
typedef char			ksByte;
typedef __int16			ks16;
typedef unsigned __int16 ksU16;
typedef unsigned __int16 u16;
typedef unsigned __int8	ksU8;

#if _DEBUG
	#define if_ks_dbg	if
	#define DEBUG_PRINT	printf
#else
	#define if_ks_dbg(x)
	#define DEBUG_PRINT
#endif

namespace ks {

	template<typename T> struct strip_ref			{ typedef T type; };

	template<typename T> struct strip_ref < T& >	{ typedef T type; };
	template<typename T> struct strip_ref < T&& >	{ typedef T type; };

	template <typename T>
	typename strip_ref<T>::type&& move(T&& arg)		{ return static_cast<typename strip_ref<T>::type&&>(arg); }


	//////////////////////////////////////////////////////////////////////////
	// removes constness, pointers or ref qualifiers, so we just get the plain Type
	//////////////////////////////////////////////////////////////////////////
	template<typename T> struct strip_qualifiers			{ typedef T Type; };
	template<typename T> struct strip_qualifiers<T&>		{ typedef T Type; };
	template<typename T> struct strip_qualifiers<const T>	{ typedef T Type; };
	template<typename T> struct strip_qualifiers<const T&>	{ typedef T Type; };
	template<typename T> struct strip_qualifiers<const T*>	{ typedef T* Type; };


	template<typename T> struct bare_type			{ typedef T Type; };
	template<typename T> struct bare_type<T&>		{ typedef T Type; };
	template<typename T> struct bare_type<T*>		{ typedef T Type; };
	template<typename T> struct bare_type<const T>	{ typedef T Type; };
	template<typename T> struct bare_type<const T&>	{ typedef T Type; };
	template<typename T> struct bare_type<const T*>	{ typedef T Type; };
	template<typename T> struct bare_type<const T**>{ typedef T Type; };

}


#endif // KS_DEFINES_H