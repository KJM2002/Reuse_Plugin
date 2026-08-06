#include "Prototype/JMPrototypeTypes.h"

FJMPrototypeOperationResult FJMPrototypeOperationResult::Success(const FText& InMessage)
{
	FJMPrototypeOperationResult Result;
	Result.bSucceeded = true;
	Result.Code = EJMPrototypeOperationCode::Success;
	Result.Message = InMessage;
	return Result;
}

FJMPrototypeOperationResult FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode InCode, const FText& InMessage)
{
	FJMPrototypeOperationResult Result;
	Result.Code = InCode;
	Result.Message = InMessage;
	return Result;
}
