# Checklist dos Requisitos da Apresentação Final

- [ ] **1. Definição do cenário**
    - [ ] **1.1. Coerência temática (Obrigatório)**
        - O cenário deve ter coerência temática (não pode ser um amontoado de objetos aleatórios).
    - [ ] **1.2. Coordenadas do mundo (Obrigatório)**
        - Todos os objetos devem estar no primeiro octante (x, y e z positivos).
    - [x] **1.3. Objetos**
        - [x] **1.3.1. Tipos de objetos (apresentar pelo menos um objeto de cada tipo) (Obrigatório)**
            - [x] Esfera
            - [x] Cilindro
            - [x] Cone
            - [x] Malha
        - [ ] **1.3.2. Materiais (pelo menos quatro materiais distintos) (Obrigatório)**
        - [ ] **1.3.3. Textura (pelo menos uma textura aplicada) (Obrigatório)**
    - [ ] **1.4. Transformações**
        - [x] **1.4.1. Translação (Obrigatório)**
        - [x] **1.4.2. Rotação**
            - [x] Em torno de um dos eixos x, y ou z (Obrigatório)
            - [x] Em torno de um eixo arbitrário
                - [x] Quatérnios
        - [x] **1.4.3. Escala (Obrigatório)**
        - [ ] **1.4.4. Cisalhamento (+0.5)**
        - [ ] **1.4.5. Espelho em relação a um plano arbitrário (+0.5)**
    - [ ] **1.5. Fontes luminosas**
        - [x] **1.5.1. Pontual (Obrigatório)**
        - [ ] **1.5.2. Spot (+1.0)**
        - [ ] **1.5.3. Direcional (+0.5)**
        - [x] **1.5.4. Ambiente (Obrigatório)**

- [ ] **2. Câmera**
    - [ ] **2.1. Permitir a especificação de (Obrigatório)**
        - [ ] Posição da câmera (Eye)
        - [ ] Direcionamento de visada (At point)
        - [ ] Orientação da câmara em torno do eixo de visada (Up point)
    - [ ] **2.2. Parâmetros adicionais (Obrigatório)**
        - [ ] Distância focal (d)
        - [ ] Campo de visão (definir as coordenadas da janela: xmin, xmax, ymin, ymax)

- [ ] **3. Projeções**
    - [ ] **3.1. Perspectiva (Obrigatório)**
        - [ ] Alterar os parâmetros adicionais da câmera para:
            - [ ] Aumentar o campo de visão (zoom out) (Obrigatório)
            - [ ] Diminuir o campo de visão (zoom in) (Obrigatório)
        - [ ] Demonstrar como posicionar a câmera para obter:
            - [ ] Perspectiva com um ponto de fuga (+0.5)
            - [ ] Perspectiva com dois pontos de fuga (+0.5)
            - [ ] Perspectiva com três ou mais pontos de fuga (+0.5)
    - [ ] **3.2. Ortográfica (+0.5)**
    - [ ] **3.3. Obliqua (+0.5)**

- [x] **4. Sombra (Obrigatório)**

- [ ] **5. Interatividade**
    - [ ] **5.1. Implementar a função de pick (Obrigatório)**
    - [ ] **5.2. Uso de interface gráfica (Bônus de 0.5 a 1.0)**

- [x] **6. Imagem gerada por ray casting com pelo menos 500 x 500 pixels (Obrigatório)**

- [ ] **7. Bônus de criatividade e beleza (até 1.0)**
