
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

void generateFile(const std::string &path, const std::string &content)
{
	std::ofstream file(path);
	if (file.is_open())
	{
		file << content;
		file.close();
		std::cout << "Generated: " << path << std::endl;
	}
	else
	{
		std::cerr << "Failed to create file: " << path << std::endl;
	}
}

void generateSearchFiles(std::string &entityName, std::string &rootPath)
{
	std::string camelCaseEntityName = entityName;
	camelCaseEntityName[0] = tolower(camelCaseEntityName[0]);
	entityName[0] = toupper(entityName[0]);

	generateFile("./" + camelCaseEntityName + "/port/in/Search" + entityName + "UseCase.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".port.in;\n\n"
																	 "import " +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import java.util.List;\n\n"
																					  "public interface Search" +
					 entityName + "UseCase {\n\n"
								  "    List<" +
					 entityName + "> searchAll();\n\n"
								  "    " +
					 entityName + " searchById(Long id);\n\n"
								  "}");

	generateFile("./" + camelCaseEntityName + "/port/out/Find" + entityName + "Port.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".port.out;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import java.util.List;\n\n"
																					  "public interface Find" +
					 entityName + "Port {\n\n"
								  "    List<" +
					 entityName + "> findAll();\n\n"
								  "    " +
					 entityName + " findById(Long id);\n\n" +
					 "    List<" +
					 entityName + "> findAllByIdList(List<Long> idList);\n\n"
								  "}");

	generateFile("./" + camelCaseEntityName + "/service/Search" + entityName + "Service.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".service;\n\n"
																	 "import " +
					 camelCaseEntityName + ".port.in.Search" + entityName + "UseCase;\n"
																			"import " +
					 camelCaseEntityName + ".port.out.Find" + entityName + "Port;\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import lombok.RequiredArgsConstructor;\n"
																					  "import org.springframework.stereotype.Service;\n\n"
																					  "import java.util.List;\n\n"
																					  "@Service\n"
																					  "@RequiredArgsConstructor\n"
																					  "public class Search" +
					 entityName + "Service implements Search" + entityName + "UseCase {\n\n"
																			 "    private final Find" +
					 entityName + "Port find" + entityName + "Port;\n\n"
															 "    @Override\n"
															 "    public List<" +
					 entityName + "> searchAll() {\n"
								  "        return find" +
					 entityName + "Port.findAll();\n"
								  "    }\n\n"
								  "    @Override\n"
								  "    public " +
					 entityName + " searchById(Long id) {\n"
								  "        return find" +
					 entityName + "Port.findById(id);\n" +
					 "    }\n\n"
					 "}");

	generateFile("./" + camelCaseEntityName + "/adapter/out/Find" + entityName + "Adapter.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".adapter.out;\n\n"
																	 "import " +
					 camelCaseEntityName + ".port.out.Find" + entityName + "Port;\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import org.springframework.stereotype.Repository;\n"
																					  "import lombok.RequiredArgsConstructor;\n\n" +
					 "import java.util.List;\n\n"
					 "@Repository\n"
					 "@RequiredArgsConstructor\n"
					 "public class Find" +
					 entityName + "Adapter implements Find" + entityName + "Port {\n\n"
																		   "    private final " +
					 entityName + "Repository repository;\n\n"
								  "    @Override\n"
								  "    public List<" +
					 entityName + "> findAll() {\n"
								  "        return repository.findAll();\n"
								  "    }\n\n"
								  "    @Override\n"
								  "    public " +
					 entityName + " findById(Long id) {\n"
								  "        return repository.findById(id).orElse(null);\n"
								  "    }\n\n" +
					 "    @Override\n"
					 "    public List<" +
					 entityName + "> findAllByIdList(List<Long> idList) {\n"
								  "        return repository.findAllByIds(idList);\n"
								  "    }\n\n"
								  "}");
}

void generateRegisterFiles(std::string &entityName, std::string &rootPath)
{
	std::string camelCaseEntityName = entityName;
	camelCaseEntityName[0] = tolower(camelCaseEntityName[0]);
	entityName[0] = toupper(entityName[0]);

	generateFile("./" + camelCaseEntityName + "/port/in/Register" + entityName + "UseCase.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".port.in;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import java.util.List;\n\n"
																					  "public interface Register" +
					 entityName + "UseCase {\n\n"
								  "    " +
					 entityName + " register(" + entityName + " entity);\n\n"
															  "    List<" +
					 entityName + "> registerAll(List<" + entityName + "> entities);\n\n"
																	   "}");

	generateFile("./" + camelCaseEntityName + "/port/out/Register" + entityName + "Port.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".port.out;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n" +
					 "import java.util.List;\n\n"
					 "public interface Register" +
					 entityName + "Port {\n\n"
								  "    " +
					 entityName + " register(" + entityName + " entity);\n\n"
															  "    List<" +
					 entityName + "> registerAll(List<" + entityName + "> entities);\n\n"
																	   "}");

	generateFile("./" + camelCaseEntityName + "/service/Register" + entityName + "Service.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".service;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import " +
					 camelCaseEntityName + ".port.in.Register" + entityName + "UseCase;\n"
																			  "import " +
					 camelCaseEntityName + ".port.out.Register" + entityName + "Port;\n"
																			   "import lombok.RequiredArgsConstructor;\n"
																			   "import org.springframework.stereotype.Service;\n\n"
																			   "import java.util.List;\n\n"
																			   "@Service\n"
																			   "@RequiredArgsConstructor\n"
																			   "public class Register" +
					 entityName + "Service implements Register" + entityName + "UseCase {\n\n"
																			   "    private final Register" +
					 entityName + "Port register" + entityName + "Port;\n\n"
																 "    @Override\n"
																 "    public List<" +
					 entityName + "> registerAll(List<" + entityName + "> entities) {\n"
																	   "        return register" +
					 entityName + "Port.registerAll(entities);\n"
								  "    }\n\n"
								  "    @Override\n"
								  "    public " +
					 entityName + " register(" + entityName + " entity) {\n"
															  "        return register" +
					 entityName + "Port.register(entity);\n"
								  "    }\n\n"
								  "}");

	generateFile("./" + camelCaseEntityName + "/adapter/out/Register" + entityName + "Adapter.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".adapter.out;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import " +
					 camelCaseEntityName + ".port.out.Register" + entityName + "Port;\n"
																			   "import org.springframework.stereotype.Repository;\n"
																			   "import lombok.RequiredArgsConstructor;\n\n" +
					 "import java.util.List;\n\n"
					 "@Repository\n"
					 "@RequiredArgsConstructor\n"
					 "public class Register" +
					 entityName + "Adapter implements Register" + entityName + "Port {\n\n"
																			   "    private final " +
					 entityName + "Repository repository;\n\n"
								  "    @Override\n"
								  "    public List<" +
					 entityName + "> registerAll(List<" + entityName + "> entities) {\n"
																	   "        return repository.saveAll(entities);\n"
																	   "    }\n\n"
																	   "}");
}

void generateModifyFiles(std::string &entityName, std::string &rootPath)
{
	std::string camelCaseEntityName = entityName;
	camelCaseEntityName[0] = tolower(camelCaseEntityName[0]);
	entityName[0] = toupper(entityName[0]);

	generateFile("./" + camelCaseEntityName + "/port/in/Modify" + entityName + "UseCase.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".port.in;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import java.util.List;\n\n"
																					  "public interface Modify" +
					 entityName + "UseCase {\n\n"
								  "    " +
					 entityName + " modify(" + entityName + " entity);\n\n"
															"    List<" +
					 entityName + "> modifyAll(List<" + entityName + "> entities);\n\n"
																	 "}");

	generateFile("./" + camelCaseEntityName + "/port/out/Modify" + entityName + "Port.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".port.out;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import java.util.List;\n\n" +
					 "public interface Modify" +
					 entityName + "Port {\n\n"
								  "    " +
					 entityName + " modify(" +
					 entityName + " entity);\n\n"
								  "    List<" +
					 entityName + "> modifyAll(List<" +
					 entityName + "> entities);\n\n"
								  "}");

	generateFile("./" + camelCaseEntityName + "/service/Modify" + entityName + "Service.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".service;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import " +
					 camelCaseEntityName + ".port.in.Modify" + entityName + "UseCase;\n"
																			"import " +
					 camelCaseEntityName + ".port.out.Find" + entityName + "Port;\n" +
					 "import " +
					 camelCaseEntityName + ".port.out.Modify" + entityName + "Port;\n" +
					 "import lombok.RequiredArgsConstructor;\n"
					 "import org.springframework.stereotype.Service;\n\n"
					 "import java.util.List;\n"
					 "import java.util.stream.Collectors;\n\n"
					 "@Service\n"
					 "@RequiredArgsConstructor\n"
					 "public class Modify" +
					 entityName + "Service implements Modify" + entityName + "UseCase {\n\n"
																			 "    private final Modify" +
					 entityName + "Port modify" + entityName + "Port;\n" +
					 "    private final Find" +
					 entityName + "Port find" + entityName + "Port;\n\n"
															 "    @Override\n"
															 "    public " +
					 entityName + " modify(" + entityName + " entity) {\n"
															"        " +
					 entityName + " existingEntity = find" +
					 entityName +
					 "Port.findById(entity.getId());\n"
					 "        if (existingEntity == null) {\n"
					 "            throw new IllegalArgumentException(\"Entity not found\");\n"
					 "        }\n"
					 "        return modify" +
					 entityName + "Port.modify(entity);\n"
								  "    }\n\n"
								  "    @Override\n"
								  "    public List<" +
					 entityName + "> modifyAll(List<" + entityName + "> entities) {\n"
																	 "        List<" +
					 entityName + "> existingEntities = find" +
					 entityName + "Port.findAllByIdList(entities.stream().map(" + entityName + "::getId).collect(Collectors.toList()));\n"
																							   "        if (existingEntities.size() != entities.size()) {\n"
																							   "            throw new IllegalArgumentException(\"Some entities not found\");\n"
																							   "		}\n" +
					 "        return modify" + entityName + "Port.modifyAll(entities);\n"
															"    }\n\n"
															"}");

	generateFile("./" + camelCaseEntityName + "/adapter/out/Modify" + entityName + "Adapter.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".adapter.out;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import " +
					 camelCaseEntityName + ".port.out.Modify" + entityName + "Port;\n"
																			 "import org.springframework.stereotype.Repository;\n"
																			 "import lombok.RequiredArgsConstructor;\n\n" +
					 "import java.util.List;\n\n"
					 "@Repository\n"
					 "@RequiredArgsConstructor\n"
					 "public class Modify" +
					 entityName + "Adapter implements Modify" + entityName + "Port {\n\n"
																			 "    private final " +
					 entityName + "Repository repository;\n\n"
								  "    @Override\n"
								  "    public List<" +
					 entityName + "> modifyAll(List<" + entityName + "> entities) {\n"
																	 "        return repository.saveAll(entities);\n"
																	 "    }\n\n"
																	 "}");
}

void generateDeleteFiles(std::string &entityName, std::string &rootPath)
{
	std::string camelCaseEntityName = entityName;
	camelCaseEntityName[0] = tolower(camelCaseEntityName[0]);
	entityName[0] = toupper(entityName[0]);

	generateFile("./" + camelCaseEntityName + "/port/in/Delete" + entityName + "UseCase.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".port.in;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import java.util.List;\n\n"
																					  "public interface Delete" +
					 entityName + "UseCase {\n\n"
								  "    void deleteById(Long id);\n\n"
								  "    void deleteAllByIdList(List<Long> idList);\n\n"
								  "}");

	generateFile("./" + camelCaseEntityName + "/port/out/Delete" + entityName + "Port.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".port.out;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n" +
					 "import java.util.List;\n\n" +
					 "public interface Delete" +
					 entityName + "Port {\n\n"
								  "    void delete(" +
					 entityName + " entity);\n\n"
								  "    void deleteAll(List<" +
					 entityName + "> entities);\n\n"
								  "}");

	generateFile("./" + camelCaseEntityName + "/service/Delete" + entityName + "Service.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".service;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import " +
					 camelCaseEntityName + ".port.in.Delete" + entityName + "UseCase;\n"
																			"import " +
					 camelCaseEntityName + ".port.out.Delete" + entityName + "Port;\n" +
					 "import " + camelCaseEntityName + ".port.out.Find" + entityName + "Port;\n\n" +
					 "import lombok.RequiredArgsConstructor;\n"
					 "import org.springframework.stereotype.Service;\n\n"
					 "import java.util.List;\n"
					 "import java.util.stream.Collectors;\n\n" +
					 "@Service\n"
					 "@RequiredArgsConstructor\n"
					 "public class Delete" +
					 entityName + "Service implements Delete" + entityName + "UseCase {\n\n" +
					 "    private final Find" +
					 entityName + "Port find" + entityName + "Port;\n\n" +
					 "    private final Delete" +
					 entityName + "Port delete" + entityName + "Port;\n\n"
															   "    @Override\n" +
					 "    public void deleteById(Long id) {\n"
					 "        " +
					 entityName + " entity = find" +
					 entityName + "Port.findById(id);\n"
								  "        if (entity == null) {\n"
								  "            throw new IllegalArgumentException(\"Entity not found\");\n"
								  "        }\n"
								  "        delete" +
					 entityName + "Port.delete(entity);\n"
								  "    }\n\n"
								  "    @Override\n"
								  "    public void deleteAllByIdList(List<Long> idList) {\n"
								  "        List<" +
					 entityName + "> entities = find" +
					 entityName + "Port.findAllByIdList(idList);\n"
								  "        if (entities.size() != idList.size()) {\n"
								  "            throw new IllegalArgumentException(\"Some entities not found\");\n"
								  "        }\n"
								  "        delete" +
					 entityName + "Port.deleteAll(entities);\n"
								  "    }\n\n"
								  "}");

	generateFile("./" + camelCaseEntityName + "/adapter/out/Delete" + entityName + "Adapter.java",
				 "package " + rootPath + "/" + camelCaseEntityName + ".adapter.out;\n\n" +
					 "import " + camelCaseEntityName + ".port.domain." + entityName + ";\n\n"
																					  "import " +
					 camelCaseEntityName + ".port.out.Delete" + entityName + "Port;\n"
																			 "import org.springframework.stereotype.Repository;\n"
																			 "import lombok.RequiredArgsConstructor;\n\n" +
					 "import java.util.List;\n\n"
					 "@Repository\n"
					 "@RequiredArgsConstructor\n"
					 "public class Delete" +
					 entityName + "Adapter implements Delete" + entityName + "Port {\n\n"
																			 "    private final " +
					 entityName + "Repository repository;\n\n" +
					 "    @Override\n"
					 "    public void delete(" +
					 entityName + " entity) {\n" +
					 "        repository.delete(entity);\n" +
					 "    }\n\n" +
					 "    @Override\n" +
					 "    public void deleteAll(List<" +
					 entityName + "> entities) {\n"
								  "        repository.deleteAll(entities);\n"
								  "    }\n\n"
								  "}");
}

void createCrudFiles(std::string &entityName, std::string &rootPath)
{
	std::string camelCaseEntityName = entityName;
	camelCaseEntityName[0] = tolower(camelCaseEntityName[0]);
	std::string basePath = "./" + camelCaseEntityName;
	entityName[0] = toupper(entityName[0]);

	// Create directories
	std::filesystem::create_directories(basePath + "/adapter/out");
	std::filesystem::create_directories(basePath + "/port/in");
	std::filesystem::create_directories(basePath + "/port/out");
	std::filesystem::create_directories(basePath + "/service");

	// Generate {EntityName}Repository.java if it doesn't exist
	std::string repositoryPath = "./infrastructure/" + entityName + "Repository.java";
	if (!std::filesystem::exists(repositoryPath))
	{
		generateFile(repositoryPath,
					 "package infrastructure;\n\n"
					 "import org.springframework.data.jpa.repository.JpaRepository;\n\n"
					 "public interface " +
						 entityName + "Repository extends JpaRepository<" + entityName + ", Long> {\n"
																						 "    // Define custom query methods here\n"
																						 "}");
	}

	generateSearchFiles(entityName, rootPath);
	generateRegisterFiles(entityName, rootPath);
	generateModifyFiles(entityName, rootPath);
	generateDeleteFiles(entityName, rootPath);
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <EntityName>" << std::endl;
		return EXIT_FAILURE;
	}

	std::string rootDirectory;
	for (const auto &entry : std::filesystem::recursive_directory_iterator("."))
	{
		if (entry.path().extension() == ".java")
		{
			std::ifstream file(entry.path());
			std::string line;
			while (std::getline(file, line))
			{
				if (line.find("@SpringBootApplication") != std::string::npos)
				{
					rootDirectory = entry.path().parent_path().string();
					break;
				}
			}
			if (!rootDirectory.empty())
			{
				break;
			}
		}
	}

	if (rootDirectory.empty())
	{
		std::cerr << "Error: Could not find a file with @SpringBootApplication annotation." << std::endl;
		return EXIT_FAILURE;
	}

	std::string entityName = argv[1];
	std::filesystem::current_path(rootDirectory);
	std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
	std::cout << "Generating CRUD files for entity: " << entityName << std::endl;
	std::cout << "Root directory: " << rootDirectory << std::endl;
	createCrudFiles(entityName, rootDirectory);

	return EXIT_SUCCESS;
}