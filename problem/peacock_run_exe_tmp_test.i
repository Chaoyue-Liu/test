[Mesh]
  type = FileMesh
  file = mesh2.inp
[]

[Variables]
  [phis]
    initial_condition = '1'
    block = 'Surface1_TRI3'
  []
  [phil]
    initial_condition = '1'
    block = 'Surface2_TRI3'
  []
  [cl]
    initial_condition = '1000'
  []
[]

[Materials]
  [mats]
    type = GenericConstantMaterial
    prop_names = 'sigma D'
    prop_values = '40 10'
    block = 'Surface1_TRI3'
  []
  [matl]
    type = GenericConstantMaterial
    prop_names = 'sigma D'
    prop_values = '20 10'
    block = 'Surface2_TRI3'
  []
[]

[Kernels]
  [phi_s]
    type = MatDiffusion
    variable = phis
    diffusivity = sigma
    block = 'Surface1_TRI3'
  []
  [phi_l]
    type = MatDiffusion
    variable = phil
    diffusivity = sigma
    block = 'Surface2_TRI3'
  []
  [c_l]
    type = MatDiffusion
    variable = cl
    diffusivity = D
  []
[]

[InterfaceKernels]
  [penalty]
    type = myPenaltyInterfaceDiffusion
    variable = phis
    neighbor_var = 'phil'
    cl = 'cl'
    boundary = 'Line1'
    penalty = 1
  []
[]

[AuxVariables]
  [dphis]
    family = MONOMIAL
    order = FIRST
  []
  [dphil]
    family = MONOMIAL
    order = FIRST
  []
[]

[AuxKernels]
  [diffusion_phis]
    type = DiffusionFluxAux
    component = y
    diffusion_variable = 'phis'
    diffusivity = sigma
    variable = dphis
    block = 'Surface1_TRI3'
  []
  [diffusion_phil]
    type = DiffusionFluxAux
    component = y
    diffusion_variable = 'phil'
    diffusivity = sigma
    variable = dphil
    block = 'Surface2_TRI3'
  []
[]

[BCs]
  [phis_top]
    type = ADDirichletBC
    variable = phis
    boundary = 'Line3'
    value = 1
  []
  [phil_low]
    type = ADNeumannBC
    variable = phil
    boundary = 'Line7'
    value = 3
  []
  [cl_left]
    type = ADDirichletBC
    variable = cl
    boundary = 'Line4'
    value = 1000
  []
  [cl_right]
    type = ADDirichletBC
    variable = cl
    boundary = 'Line6'
    value = 10
  []
[]

[Executioner]
  type = Steady
  solve_type = NEWTON
[]

[Outputs]
  exodus = true
[]
