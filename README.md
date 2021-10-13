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
