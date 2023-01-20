// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoulProtectorGameMode.h"
#include "SoulProtectorCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASoulProtectorGameMode::ASoulProtectorGameMode()
{
	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/
}
