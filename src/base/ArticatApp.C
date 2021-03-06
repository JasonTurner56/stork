#include "ArticatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<ArticatApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

ArticatApp::ArticatApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ArticatApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ArticatApp::associateSyntax(_syntax, _action_factory);
}

ArticatApp::~ArticatApp()
{
}

// External entry point for dynamic application loading
extern "C" void ArticatApp__registerApps() { ArticatApp::registerApps(); }
void
ArticatApp::registerApps()
{
  registerApp(ArticatApp);
}

// External entry point for dynamic object registration
extern "C" void ArticatApp__registerObjects(Factory & factory) { ArticatApp::registerObjects(factory); }
void
ArticatApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void ArticatApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { ArticatApp::associateSyntax(syntax, action_factory); }
void
ArticatApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
