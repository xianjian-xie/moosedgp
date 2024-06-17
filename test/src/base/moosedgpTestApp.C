//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "moosedgpTestApp.h"
#include "moosedgpApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
moosedgpTestApp::validParams()
{
  InputParameters params = moosedgpApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

moosedgpTestApp::moosedgpTestApp(InputParameters parameters) : MooseApp(parameters)
{
  moosedgpTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

moosedgpTestApp::~moosedgpTestApp() {}

void
moosedgpTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  moosedgpApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"moosedgpTestApp"});
    Registry::registerActionsTo(af, {"moosedgpTestApp"});
  }
}

void
moosedgpTestApp::registerApps()
{
  registerApp(moosedgpApp);
  registerApp(moosedgpTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
moosedgpTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  moosedgpTestApp::registerAll(f, af, s);
}
extern "C" void
moosedgpTestApp__registerApps()
{
  moosedgpTestApp::registerApps();
}
