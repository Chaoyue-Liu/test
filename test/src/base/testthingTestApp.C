//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "testthingTestApp.h"
#include "testthingApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
testthingTestApp::validParams()
{
  InputParameters params = testthingApp::validParams();
  return params;
}

testthingTestApp::testthingTestApp(InputParameters parameters) : MooseApp(parameters)
{
  testthingTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

testthingTestApp::~testthingTestApp() {}

void
testthingTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  testthingApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"testthingTestApp"});
    Registry::registerActionsTo(af, {"testthingTestApp"});
  }
}

void
testthingTestApp::registerApps()
{
  registerApp(testthingApp);
  registerApp(testthingTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
testthingTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  testthingTestApp::registerAll(f, af, s);
}
extern "C" void
testthingTestApp__registerApps()
{
  testthingTestApp::registerApps();
}
