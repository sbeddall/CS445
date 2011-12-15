#ifndef ENUMS
#define ENUMS

enum rules {
  nativeType = 500,
  variableName, //501
  variableBinding, //502
  variableDeclarationList, //503
  variableDeclaration, //504
  optionalVariableType, //505
  variableInitialization, //506
  variableKind, //507
  value, //508
  mathValue, //509
  expr, //510
  expression, //511
  sourceElements, //512
  sourceElement, //513 
  statement, //514
  program, //515
  objectInitializer, //516
  newObject, //517
  arrayAccessor, //518
  functionCall, //519
  ternaryExpression, //520
  block , //521
  importStatement , //522
  functionStatement , //523
  forStatement, //524
  ifStatement , //525
  whileStatement , //526
  continueStatement , //527
  breakStatement, //528
  withStatement , //529
  throwStatement , //530
  tryStatement , //531
  iterationStatement, //532
  superStatement, //533
  classStatement, //534
  packageStatement, //535
  returnStatement, //536
  assignStatement, //537
  getterSetter, //538
  valueList, //539
  as, //540
  functionDeclaration, //541
  logicalOperator, //542
  accessValue, //543
  optionalForIncrement, //544
  assign, //545
  functionHeader, //546
  elseStatement, //547
  prefixKeyword, //548
  suffixKeyword, //549
  modifier, //550
  modifierPrefix, //551
  modifierSuffix, //552
  optionalForConditional, //553
  finally, //554
  catch, //555
};

enum opcodes {
  ASN = 700,
  ADD,
  SUB,
  MUL,
  DIV,
  MOD,
  NEG,
  ADDR,
  LCONT,
  SCONT,
  GOTO,
  BLESS,
  BIF,
  BNIF,
  PARM,
  CALL,
  RET,
  proc,
  class,
  package,
};

#endif
