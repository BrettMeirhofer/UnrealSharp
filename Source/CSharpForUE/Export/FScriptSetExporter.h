﻿#pragma once

#include "CoreMinimal.h"
#include "FunctionsExporter.h"
#include "FScriptSetExporter.generated.h"

using FGetKeyHash = uint32(*)(const void*);
using FEqualityFn = bool(*)(const void*, const void*);
using FConstructFn = void(*)(void*);
using FDestructFn = void(*)(void*);

UCLASS(meta=(NotGeneratorValid))
class CSHARPFORUE_API UFScriptSetExporter : public UFunctionsExporter
{
	GENERATED_BODY()

public:

	// UFunctionsExporter interface
	virtual void ExportFunctions(FRegisterExportedFunction RegisterExportedFunction) override;
	// End of UFunctionsExporter interface

private:

	static bool IsValidIndex(FScriptSet* ScriptSet, int32 Index);
	static int Num(FScriptSet* ScriptSet);
	static int GetMaxIndex(FScriptSet* ScriptSet);
	static void* GetData(int Index, FScriptSet* ScriptSet, FScriptSetLayout* Layout);
	static void Empty(int Slack, FScriptSet* ScriptSet, FScriptSetLayout* Layout);
	static void RemoveAt(int Index, FScriptSet* ScriptSet, FScriptSetLayout* Layout);
	static int AddUninitialized(FScriptSet* ScriptSet, FScriptSetLayout* Layout);
	static void Add(FScriptSet* ScriptSet, const FScriptSetLayout& Layout, const void* Element, FGetKeyHash GetKeyHash, FEqualityFn EqualityFn, FConstructFn ConstructFn, FDestructFn DestructFn);
	static int32 FindOrAdd(FScriptSet* ScriptSet, const void* Element, const FScriptSetLayout& Layout, FGetKeyHash GetKeyHash, FEqualityFn
	                       EqualityFn, FConstructFn ConstructFn);
	static void Rehash(FScriptSet* ScriptSet, const FScriptSetLayout& ScriptSetLayout, FGetKeyHash GetKeyHash);
	static FScriptSetLayout GetScriptSetLayout(int elementSize, int elementAlignment);
	
	
};
