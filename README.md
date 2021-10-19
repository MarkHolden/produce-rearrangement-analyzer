# Produce Rearrangement Analyzer
This application will enable you to rearrange your grocery store to the optimal layout to bring the most commonly purchased items to a place where customers can easily find them. Want to sell more of a high margin product? This analyzer will tell you which products to sandwich it between! The possibilities are endless.

### Setup
To properly copy the Python dll into the right directory, modify the `ProduceRearrangementAnalyzer.vcxproj` file to change the `Include` location to the location on your machine.
```
<ItemGroup>
  <Content Include="C:\[...]\Python\Python38-32\python3.dll">
    <CopyToOutputDirectory>PreserveNewest</CopyToOutputDirectory>
  </Content>
</ItemGroup>
```

## Project Summary
The intent of the project is to give users data about the frequency of produce purchases in order to make informed business decisions about the arrangement of the produce section.
The problem being solved is that under the current system, all the produce purchases are appended to a text document that makes it very difficult for descision makers to identify patterns.

#### What did you do particularly well?
On this project, something that I did well was to use small meaningful commits when developing. This leaves behind meaningful commit messages, and also, since I did an abhorent job at unit testing, if there is a bug discovered, commits can be rolled back as needed and the project will still build and run regardless of which commit is selected.

## Future Enhancement Potential
The number one place that needs enhancement on this project is in unit testing. Because it was not designed with testing in mind, writing tests for it now will be challenging, but will enable code changes without wondering if those changes are breaking changes for other sections of code.

## Challenges
The most challenging sections of the code are the connection points between different languages. Obviously, the necessity to use multiple different languages has to be contrived for a student project, because in reality, the given situation would absolutely not warrant the additional complexity of bringing in Python when C++ has all the tools necessary to process the data. It's good to explore those issues on a simplistic project however, because if the situaltion really required a tool or framework that was not available in C++, the complexity of the overall solution would make implementation of the connection more challenging.

The second challenge is running in release mode. I found out this evening from watching the recommended video from Uncle Bob Martin, that he recommends the use of Test Driven Development to the point where debugging skills atrophy. He maintains that if you have a good test suite, you won't need to use the debugger. Given that I wrote a total of 0 tests for this solution, I had the worst of both worlds.

I overcame these challenges the same way that I have done for the past 5 years of my software engineering career - Stack Overflow, Google, and reading docs. I didn't find any new resources during this exersize that I didn't already know about, but I always have my eye open.

#### Transferrable skills
Something that I learned about Python is that in order to get a similar type of intellisense for methods on hover, comments can be left at the top (inside the method declaration) using the `"""Documentation Comment"""` format. That will come in handy for any other Python projects I work on.

## Maintainability, Readability, and Adaptability
In order to have reusable code, the menu class was adapted from the Clock Widget project that I wrote earlier in this course. The Menu is actually simpler in this program, so I was able to rip out quite a bit of code and get down to a pretty reliable menu. A good thing about having written this menu is that I am not very familiar with C++ packages that can be pulled in to take care of things like the menu, or other implementation details that I don't want to deal with, so since I implemented it myself, I can pull in this "package" and have the expectation that it will function as expected.

To make the program readable, I used standard XML documentation comments for each method to enable me to hover over a method name and get intellisense hints about useage. I'm on preview 5 of VS 2022 now, and it's pretty great for C++. To make the code adaptable, I left a lot of cruft in the Python connector class because I don't want to have to write all that again. So there are different overloads that are not used in this project that are there for future extension.
