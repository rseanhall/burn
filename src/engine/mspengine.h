#pragma once
// Copyright (c) .NET Foundation and contributors. All rights reserved. Licensed under the Microsoft Reciprocal License. See LICENSE.TXT file in the project root for full license information.


#if defined(__cplusplus)
extern "C" {
#endif


// constants


// structures


// typedefs


// function declarations

HRESULT MspEngineParsePackageFromXml(
    __in IXMLDOMNode* pixnBundle,
    __in BURN_PACKAGE* pPackage
    );
void MspEnginePackageUninitialize(
    __in BURN_PACKAGE* pPackage
    );
HRESULT MspEngineDetectInitialize(
    __in BURN_PACKAGES* pPackages
    );
HRESULT MspEngineAddDetectedTargetProduct(
    __in BURN_PACKAGES* pPackages,
    __in BURN_PACKAGE* pPackage,
    __in DWORD dwOrder,
    __in_z LPCWSTR wzProductCode,
    __in MSIINSTALLCONTEXT context
    );
HRESULT MspEngineAddMissingSlipstreamTarget(
    __in BURN_PACKAGE* pMsiPackage,
    __in BURN_SLIPSTREAM_MSP* pSlipstreamMsp
    );
HRESULT MspEngineDetectPackage(
    __in BURN_PACKAGE* pPackage,
    __in BURN_USER_EXPERIENCE* pUserExperience
    );
HRESULT MspEnginePlanInitializePackage(
    __in BURN_PACKAGE* pPackage,
    __in BURN_USER_EXPERIENCE* pUserExperience
    );
HRESULT MspEnginePlanCalculatePackage(
    __in BURN_PACKAGE* pPackage,
    __in BOOL fInsideMsiTransaction
    );
HRESULT MspEnginePlanAddPackage(
    __in BOOTSTRAPPER_DISPLAY display,
    __in BURN_USER_EXPERIENCE* pUserExperience,
    __in BURN_PACKAGE* pPackage,
    __in BURN_PLAN* pPlan,
    __in BURN_LOGGING* pLog,
    __in BURN_VARIABLES* pVariables
    );
HRESULT MspEngineExecutePackage(
    __in_opt HWND hwndParent,
    __in BURN_EXECUTE_ACTION* pExecuteAction,
    __in BURN_VARIABLES* pVariables,
    __in BOOL fRollback,
    __in PFN_MSIEXECUTEMESSAGEHANDLER pfnMessageHandler,
    __in LPVOID pvContext,
    __out BOOTSTRAPPER_APPLY_RESTART* pRestart
    );
void MspEngineUpdateInstallRegistrationState(
    __in BURN_EXECUTE_ACTION* pAction,
    __in HRESULT hrExecute,
    __in BOOL fInsideMsiTransaction
    );
void MspEngineFinalizeInstallRegistrationState(
    __in BURN_PACKAGE* pPackage
    );


#if defined(__cplusplus)
}
#endif
