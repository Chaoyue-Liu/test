#pragma once

#include "InterfaceKernel.h"

/**
 * DG kernel for interfacing diffusion between two variables on adjacent blocks
 */
class myPenaltyInterfaceDiffusion : public InterfaceKernel
{
public:
  static InputParameters validParams();

  myPenaltyInterfaceDiffusion(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type) override;
  virtual Real computeQpJacobian(Moose::DGJacobianType type) override;

  const Real _penalty;

  std::string _jump_prop_name;
  const MaterialProperty<Real> * const _jump;

  const VariableValue & _cl;

  const Real F=96500;
  const Real k=1.68e-10;
  const Real R=8.314;
  const Real T=298.15;
  const Real alpha=0.5;
};