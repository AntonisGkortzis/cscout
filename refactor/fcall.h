/*
 * (C) Copyright 2003 Diomidis Spinellis.
 *
 * Function call graph information
 *
 * $Id: fcall.h,v 1.9 2004/07/24 07:56:06 dds Exp $
 */

#ifndef FCALL_
#define FCALL_

/*
 * Function call information is always associated with Id objects
 * It is thus guaranteed to match the symbol table lookup operations
 */

// C function calling information
class FCall : public Call {
private:
	Tokid definition;		// Function's definition
	Type type;			// Function's type
	bool defined;			// True if the function has been defined
public:
	// Called when outside a function body scope
	static void unset_current_fun() { current_fun = NULL; }
	// Set the function currently being parsed
	static void set_current_fun(const Type &t);
	static void set_current_fun(const Id *id);

	virtual Tokid get_definition() const { return definition; }
	virtual bool is_defined() const { return defined; }
	FCall(const Token& t, Type typ, const string &s);

	virtual ~FCall() {}
};

#endif // FCALL_
