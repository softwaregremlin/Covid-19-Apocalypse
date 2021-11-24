void CreateDataFolderIfNotExists() { 
	sceIoMkdir(g_DataPaths.Folder, 0777);
}