// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once 

#include "OnlineSubsystemTypes.h"

// This is not a USTRUCT due to cross module dependencies
struct FUniqueNetIdWrapper
{
public:

	FUniqueNetIdWrapper() 
	: UniqueNetId()
	{
	}
	FUniqueNetIdWrapper(const TSharedPtr<FUniqueNetId>& InUniqueNetId)
	: UniqueNetId(InUniqueNetId)
	{
	}

	/** Assignment operator */
	FUniqueNetIdWrapper& operator=(const FUniqueNetIdWrapper& Other)
	{
		if (&Other != this)
		{
			UniqueNetId = Other.UniqueNetId;
		}
		return *this;
	}

	/** Comparison operator */
	bool operator==(FUniqueNetIdWrapper const& Other) const
	{
		// Both invalid structs or both valid and deep comparison equality
		bool bBothValid = IsValid() && Other.IsValid();
		bool bBothInvalid = !IsValid() && !Other.IsValid();
		return (bBothInvalid || (bBothValid && (*UniqueNetId == *Other.UniqueNetId)));
	}

	/** Comparison operator */
	bool operator!=(FUniqueNetIdWrapper const& Other) const
	{
		return !(*this == Other);
	}

	/** Convert this value to a string */
	FString ToString() const
	{
		return IsValid() ? UniqueNetId->ToString() : TEXT("INVALID");
	}

	/** Is the FUniqueNetId wrapped in this object valid */
	bool IsValid() const
	{
		return UniqueNetId.IsValid() && UniqueNetId->IsValid();
	}
	
	/** 
	 * Assign a unique id to this wrapper object
	 *
	 * @param InUniqueNetId id to associate
	 */
	void SetUniqueNetId(const TSharedPtr<FUniqueNetId>& InUniqueNetId)
	{
		UniqueNetId = InUniqueNetId;
	}

	/** @return unique id associated with this wrapper object */
	const TSharedPtr<FUniqueNetId>& GetUniqueNetId() const
	{
		return UniqueNetId;
	}

	/**
	 * Dereference operator returns a reference to the FUniqueNetId
	 */
	const FUniqueNetId& operator*() const
	{
		return *UniqueNetId;
	}
	FUniqueNetId& operator*()
	{
		return *UniqueNetId;
	}

	/**
	 * Arrow operator returns a pointer to this FUniqueNetId
	 */
	const FUniqueNetId* operator->() const
	{
		return UniqueNetId.Get();
	}
	FUniqueNetId* operator->()
	{
		return UniqueNetId.Get();
	}

protected:
	TSharedPtr<class FUniqueNetId> UniqueNetId;
};