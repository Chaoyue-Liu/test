#include "testthingApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
testthingApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

testthingApp::testthingApp(InputParameters parameters) : MooseApp(parameters)
{
  testthingApp::registerAll(_factory, _action_factory, _syntax);
}

testthingApp::~testthingApp() {}

void
testthingApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"testthingApp"});
  Registry::registerActionsTo(af, {"testthingApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
testthingApp::registerApps()
{
  registerApp(testthingApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
testthingApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  testthingApp::registerAll(f, af, s);
}
extern "C" void
testthingApp__registerApps()
{
  testthingApp::registerApps();
}
