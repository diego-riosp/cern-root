#include <ROOT/RDataFrame.hxx>
#define path_dir "tutorials/rdataframe/"

void fill_tree(const char *treeName, const char *fileName) {
  ROOT::RDataFrame d(10); // Declarates a dataframe with 10 rows

  d.Define("b1", [](ULong64_t entry) -> double { return entry; },
           {"rdfentry_"}) // Define a columns with unsigned
                          // long long entry where is stored
                          // the value of rdfentry_ (the
                          // index number).
      .Define("b2", [](ULong64_t entry) -> int { return entry * entry; },
              {"rdfentry_"}) // Define a columns with unsigned
                             // long long entry where is stored
                             // the value of rdfentry_**2 (the
                             // squared index number).
      .Snapshot(treeName,
                fileName); // Create a .root fileName which
                           // stores the treeName afore created.
}

void df001_introduction() {
  auto fileName = path_dir "df001_introduction.root"; // Root file name
  auto treeName = "myTree";                           // TTree name
  fill_tree(treeName, fileName); // Creating the TTree with the afore
                                 // defined function
  ROOT::RDataFrame d(treeName, fileName,
                     {"b1"}); // Declare a df with the created .root
                              // file and the TTree. Only b1 is
                              // charged, however, if you call b2
                              // after in the code, RDF will to charge
                              // it automatically in that moment.

  auto table =
      d.Display({"rdfentry_", "b1", "b2"}); // Display all the TTree
  table->Print(); // Print the TTree. See that dispite that
                  // b2 was not charged in d, is however
                  // printed (charged in the previous line).

  auto cutb1 = [](double b1) {
    return b1 < 5.;
  }; // Define a lambda function for a boolean test
  auto cutb1b2 = [](int b2, double b1) {
    return b2 % 2 && b1 < 4.;
  }; // Define a lambda function for a boolean test (odd b2
     // numbers b2%2=1 is true and b2%2=0 is false)

  auto entries1 =
      d.Filter(cutb1) // <- no column name specified here! since
                      // b1 is the only one afore declarated in
                      // the first lambda function
          .Filter(cutb1b2, {"b2", "b1"}) // Filter for lambda
                                         // function condition
          .Count();                      // Count filtered values.
  std::cout << *entries1 << " entries passed all filters"
            << std::endl;                      // entries1 is a pointer.
                                               // *entries1 is the value
                                               // stored in that pointer.
  auto entries2 = d.Filter("b1 < 5.").Count(); // Define a lambda function
                                               // for a boolean test
  std::cout << *entries2 << " entries passed the string filter"
            << std::endl;

  auto b1b2_cut = d.Filter(cutb1b2, {"b2", "b1"}); // Filter again
                                                   // under cutb1b2
  auto minVal = b1b2_cut.Min();             // Compute minimum value and
                                            // stores it in a pointer
  auto maxVal = b1b2_cut.Max();             // Compute maximum value and
                                            // stores it in a pointer
  auto meanVal = b1b2_cut.Mean();           // Compute the average of
                                            // teh default column (b1)
  auto nonDefmeanVal = b1b2_cut.Mean("b2"); // <- Column is not the default
  std::cout << "The mean is always included between the "
               "min and the max: "
            << *minVal << " <= " << *meanVal << " <= " << *maxVal
            << std::endl;

  std::cout << "Non default mean value is: " << *nonDefmeanVal
            << std::endl;

  auto b1_cut = d.Filter(cutb1);      // Filtering by cutb1 lambda function
  auto b1Vec = b1_cut.Take<double>(); // Taking the values which
                                      // fulfill the condition in
                                      // cutb1 and storing these in a
                                      // vector b1Vec
  auto b1List = b1_cut.Take<double,
                            std::list<double>>(); // Taking the same but
                                                  // now into a list.

  std::cout << "Selected b1 entries" << std::endl;
  for (auto b1_entry : *b1List) // Vary b1_entry into *b1List to print the
                                // entries that was chosen in the b1_cut
    std::cout << b1_entry << " ";
  std::cout << std::endl;
  auto b1VecCl =
      ROOT::GetClass(b1Vec.GetPtr()); // Obtain the moemory direction
                                      // of the b1Vec object.
  std::cout << "The type of b1Vec is " << b1VecCl->GetName()
            << std::endl; // Show the type of object of b1VecCl
  std::cout << b1VecCl->Size() << std::endl;
  auto b1Mem = b1VecCl->GetListOfDataMembers();
  b1Mem->Print();
  std::cout << std::endl;

  auto hist = d.Filter(cutb1).Histo1D(); // Store the data in a TH1D
                                         // type histogram
  std::cout << "Filled h " << hist->GetEntries()
            << " times, mean: " << hist->GetMean() << std::endl;
}
