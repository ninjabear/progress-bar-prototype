        ��  ��                        �� ��     0 	        <?xml version="1.0" encoding="UTF-8" standalone="yes"?> 
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0"> 
  <assemblyIdentity type="win32" 
                    name="MyProgram" 
                    version="1.0.0.0" 
                    processorArchitecture="X86" /> 
  <description> 
    My Program Description  
  </description> 
  <dependency> 
    <dependentAssembly> 
      <assemblyIdentity type="win32" 
                        name="Microsoft.Windows.Common-Controls" 
                        version="6.0.0.0" 
                        processorArchitecture="X86" 
                        publicKeyToken="6595b64144ccf1df" 
                        language="*" /> 
    </dependentAssembly> 
  </dependency> 
  <trustInfo xmlns="urn:schemas-microsoft-com:asm.v3"> 
    <security> 
      <requestedPrivileges> 
        <requestedExecutionLevel  level="AsInvoker"  
                                  uiAccess="False" />  
      </requestedPrivileges> 
    </security> 
  </trustInfo> 
</assembly> 