#include "Types/JMHideTypes.h"

FJMHideResult FJMHideResult::Success(const FText& Message)
{
    FJMHideResult Result;
    Result.bSucceeded = true;
    Result.Code = EJMHideFailureCode::None;
    Result.Message = Message;
    return Result;
}

FJMHideResult FJMHideResult::Failure(EJMHideFailureCode Code, const FText& Message)
{
    FJMHideResult Result;
    Result.Code = Code;
    Result.Message = Message;
    return Result;
}
