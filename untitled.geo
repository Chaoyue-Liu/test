//+
SetFactory("OpenCASCADE");
Rectangle(1) = {0, 0, 0, 10, 5, 0};
//+
Extrude {0, -5, 0} {
  Curve{1}; 
}
