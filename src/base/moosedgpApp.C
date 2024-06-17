#include "moosedgpApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
moosedgpApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_bahavior") = false;
  return params;
}

moosedgpApp::moosedgpApp(InputParameters parameters) : MooseApp(parameters)
{
  moosedgpApp::registerAll(_factory, _action_factory, _syntax);
}

moosedgpApp::~moosedgpApp() {}

void
moosedgpApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<moosedgpApp>(f, af, s);
  Registry::registerObjectsTo(f, {"moosedgpApp"});
  Registry::registerActionsTo(af, {"moosedgpApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
moosedgpApp::registerApps()
{
  registerApp(moosedgpApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
moosedgpApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  moosedgpApp::registerAll(f, af, s);
}
extern "C" void
moosedgpApp__registerApps()
{
  moosedgpApp::registerApps();
}
